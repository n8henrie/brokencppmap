fn main() {
    cxx_build::bridge("src/lib.rs")
        .file("vendor/proj/proj.cpp")
        .flag("-std=c++11")
        .warnings(false)
        .compile("proj");
}
