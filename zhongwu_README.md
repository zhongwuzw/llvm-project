# How to build custom llvm and clang

1. git clone llvm and chech out Apple's release tag. like `swift/release/5.6`: `git@github.com:zhongwuzw/llvm-project.git`, we need to sync with Apple's latest release tag.
2. ``cd llvm``
3. ``mkdir build``
4. ``cd build``
5. ``cmake -G Ninja -DCMAKE_BUILD_TYPE=Release -DLLVM_ENABLE_PROJECTS=clang -DCMAKE_INSTALL_PREFIX=../zw_install ..`` , this generate the make file of llvm and clang. PS. If we don't pass ``LLVM_ENABLE_PROJECTS`` parameter, it would not build other sub-project except llvm.
6. ``ninja && ninja install``, it build the llvm and clang, install to ``../zw_install`` after build. Refer to [clang guide](https://clang.llvm.org/get_started.html)

# Write custom static analizer checker
1. git clone llvm and chech out Apple's release tag. like `swift/release/5.6`: `git@github.com:zhongwuzw/llvm-project.git`, we need to sync with Apple's latest release tag.
2. ``cd llvm``
3. ``mkdir build``
4. ``cd build``
5. ``cmake -G "Xcode" -DLLVM_ENABLE_PROJECTS=clang ..`` to generate Xcode project
6. Open ``LLVM.xcodeproj`` and select ``clang`` schema, build it. `clang` executable would build at `build/Debug/bin/clang`
7. Checker registration, see (checker_dev_manual)[https://clang-analyzer.llvm.org/checker_dev_manual.html]
8. If we need to debug, edit `clang`'s schema `Arguments Passed On Launch`, pass the arguments like `-cc1 -analyze -analyzer-checker=alpha.core /Users/zhongwu/Documents/workspace/Example_Test.c`
9. We can also use LLDB command instead of Xcode to Debug: 
    ```
    lldb -- llvm/build/Debug/bin/clang -cc1 -analyze -analyzer-checker=alpha.core /Users/zhongwu/Documents/workspace/Example_Test.c
    breakpoint set --file MainCallChecker.cpp --line 20
    process launch
    ```

# Analizer checker as a shared library
1. Sometimes it's very slow to develop custom checker, we can make our custom checker as a shared dynamic lib.
2. Based section of `Write custom static analizer checker` to build the clang firstly.
3. open the LLVM.xcodeproj and check my [commit](https://github.com/zhongwuzw/llvm-project/commit/84dc2ed69452cd067746983a6de25406cb19c259). 
4. Switch to the `CustomChecker` schema and select executable to the builded `clang`, see [screenshot](https://raw.githubusercontent.com/zhongwuzw/llvm-project/swift/release/5.6/resources/checkerDylib.png)
5. Add the [params](https://github.com/zhongwuzw/llvm-project/blob/swift/release/5.6/resources/checkerDylibRunParams.jpg?raw=true) to debug the checker. `-cc1 -analyze -load libCustomCheckers.dylib -analyzer-checker=alpha.core /Users/zhongwu/Documents/workspace/Example_Test.c`
6. If we want to use checker in a project, we can create a xcconfig to use custom clang, like [xcconfig](https://github.com/zhongwuzw/llvm-project/blob/swift/release/5.6/resources/CustomCheckers.xcconfig). If we want to execute xcodebuild command, we can also use command like : `xcodebuild -xcconfig "xcconfigPath" .... analyze`
7. If we add the new files, we don't need to execute ``cmake -G "Xcode" -DLLVM_ENABLE_PROJECTS=clang ..`` again, it's very slow, we can just use Xcode, right click to use "Add files to ...", then build again.

# clang related analysis commands
1. clang -cc1 -ast-dump test.c (dump the ast)
2. See the cfg or exploded graph in MacOS, `brew install graphviz` and `dot -Tpng test.dot -o test.png`
3. If we want to debug clang's static analyzer code, we need pass the analyzer-checker of the checker, like ```-cc1 -analyze -load libCustomCheckers.dylib  -fblocks  -verify -Wno-objc-root-class -analyzer-checker=osx.cocoa.MissingSuperCall  /Users/zhongwu/Documents/workspace/Example_Test.m```. OC static analyzer sample test code: https://github.com/zhongwuzw/llvm-project/blob/swift%2Frelease%2F5.6/clang/test/Analysis/superclass.m

# clang static analyzer related documentation
1. [ClangStaticAnalyzer](https://clang.llvm.org/docs/ClangStaticAnalyzer.html)
2. https://llvm.org/devmtg/2008-08/Kremenek_StaticAnalyzer.pdf
3. https://clang-analyzer.llvm.org/available_checks.html
4. https://clang.llvm.org/docs/analyzer/checkers.html#core-callandmessage-c-c-objc
5. https://clang.llvm.org/docs/index.html
6. There has tests of clang static analyzer in llvm-project/clang/test/Analysis directory.