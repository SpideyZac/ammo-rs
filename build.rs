fn main() {
    let mut cfg = cmake::Config::new(".");
    cfg.profile("Release");
    let dst = cfg.build();

    let lib_dir = dst.join("lib");

    println!("cargo:rustc-link-search=native={}", lib_dir.display());

    println!("cargo:rustc-link-lib=static=BulletSoftBody");
    println!("cargo:rustc-link-lib=static=BulletDynamics");
    println!("cargo:rustc-link-lib=static=BulletCollision");
    println!("cargo:rustc-link-lib=static=LinearMath");

    let mut build = cxx_build::bridge("src/lib.rs");
    if !cfg!(target_os = "windows") {
        build
            .file("src/ammo.cc")
            .cpp(true)
            .std("c++14")
            .flag_if_supported("-DBT_NO_SIMD_OPERATOR_OVERLOADS")
            .flag_if_supported("-w")
            .flag_if_supported("-O3")
            .include("ammo.js/bullet/src")
            .compiler("clang++");

        build.compile("ammo");
    } else {
        build
            .file("src/ammo.cc")
            .cpp(true)
            .std("c++14")
            .flag_if_supported("-DBT_NO_SIMD_OPERATOR_OVERLOADS")
            .flag_if_supported("/w")
            .flag_if_supported("/MD")
            .flag_if_supported("/O2")
            .include("ammo.js/bullet/src");

        build.compile("ammo");
    }

    println!("cargo:rerun-if-changed=build.rs");
    println!("cargo:rerun-if-changed=src/ammo.cc");
    println!("cargo:rerun-if-changed=include/ammo.h");
    println!("cargo:rerun-if-changed=ammo.js/bullet/");
    println!("cargo:rerun-if-changed=CMakeLists.txt");
}
