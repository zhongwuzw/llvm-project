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