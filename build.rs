use std::{env, path::PathBuf};

type Result<T> = std::result::Result<T, Box<dyn std::error::Error>>;

fn main() -> Result<()> {
    println!("cargo:rerun-if-changed=wrapper.h");
    let src = ["wrapper.cpp", "vendor/proj/proj.cpp"];

    cc::Build::new()
        .cpp(true)
        .files(src.iter())
        .flag("-std=c++11")
        .compile("proj");

    let bindings = bindgen::Builder::default()
        .header("wrapper.h")
        .clang_arg("-Ivendor/proj")
        .allowlist_function("newConfig")
        .allowlist_function("setInherited")
        .allowlist_function("printInherited")
        .allowlist_function("setComposed")
        .allowlist_function("printComposed")
        .opaque_type("std::.*")
        .generate()
        .expect("Unable to generate bindings");

    let out_path = PathBuf::from(env::var("OUT_DIR").unwrap());
    bindings
        .write_to_file(out_path.join("bindings.rs"))
        .expect("Couldn't write bindings!");
    Ok(())
}
