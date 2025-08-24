fn main() {
    cxx_build::bridge("src/lib.rs")
        .file("src/ammo.cc")
        .cpp(true)
        .std("c++14")
        .flag_if_supported("-DBT_NO_SIMD_OPERATOR_OVERLOADS")
        .flag_if_supported("-w")
        .include("ammo.js/bullet/src")
        .compiler("clang++")
        .compile("ammo");

    println!("cargo:rerun-if-changed=build.rs");
    println!("cargo:rerun-if-changed=src/ammo.cc");
    println!("cargo:rerun-if-changed=include/ammo.h");
    println!("cargo:rerun-if-changed=ammo.js/bullet/");
}
