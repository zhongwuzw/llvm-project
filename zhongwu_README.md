# How to build custom llvm and clang

1. git clone llvm and chech out Apple's release tag. like `swift/release/5.6`: `git@github.com:zhongwuzw/llvm-project.git`, we need to sync with Apple's latest release tag.
2. ``cd llvm``
3. ``mkdir build``
4. ``cd build``
5. ``cmake -G Ninja -DCMAKE_BUILD_TYPE=Release -DLLVM_ENABLE_PROJECTS=clang -DCMAKE_INSTALL_PREFIX=../zw_install ..`` , this generate the make file of llvm and clang. PS. If we don't pass ``LLVM_ENABLE_PROJECTS`` parameter, it would not build other sub-project except llvm.
6. ``ninja && ninja install``, it build the llvm and clang, install to ``../zw_install`` after build. Refer to [clang guide](https://clang.llvm.org/get_started.html)