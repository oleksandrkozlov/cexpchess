FROM ubuntu:20.04

ARG DEBIAN_FRONTEND=noninteractive

RUN apt-get update && apt-get install -y \
    ccache \
    clang \
    libclang-dev \
    clang-format \
    clang-tidy \
    cmake \
    cppcheck \
    curl \
    git \
    graphviz \
    kcov \
    libdocopt-dev \
    libfmt-dev \
    libgtest-dev \
    libspdlog-dev \
    ninja-build \
    pkg-config \
    python3 \
    python3-pip

RUN pip3 install \
    cmakelang

RUN git clone --depth=1 --branch v3.1.0 \
    https://github.com/microsoft/GSL.git gsl \
    && cmake -Hgsl -Bgsl/build -GNinja -DCMAKE_BUILD_TYPE=Release -DGSL_TEST=OFF \
    && cmake --build gsl/build \
    && cmake --install gsl/build \
    && rm -rf gsl

RUN git clone --depth=1 --branch clang_10 \
    https://github.com/include-what-you-use/include-what-you-use.git iwyu \
    && CC=clang CXX=clang++ cmake -Hiwyu -Biwyu/build -GNinja -DCMAKE_BUILD_TYPE=Release  \
    && cmake --build iwyu/build \
    && cmake --install iwyu/build \
    && rm -rf iwyu
