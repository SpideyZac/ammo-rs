#[allow(dead_code)]
#[cxx::bridge(namespace = "ammo")]
mod ffi {
    extern "Rust" {}

    unsafe extern "C++" {
        include!("ammo-rs/include/ammo.h");

        type DebugDrawer;
        type btVector3;
        type btVector4;
        type btQuadWord;

        unsafe fn DebugDrawer_new(
            drawLine: unsafe fn(&btVector3, &btVector3, &btVector3),
            drawContactPoint: unsafe fn(&btVector3, &btVector3, f32, i32, &btVector3),
            reportErrorWarning: unsafe fn(*const c_char),
            draw3dText: unsafe fn(&btVector3, *const c_char),
            setDebugMode: unsafe fn(i32),
            getDebugMode: unsafe fn() -> i32,
        ) -> UniquePtr<DebugDrawer>;
        unsafe fn DebugDrawer_drawLine(
            drawer: Pin<&mut DebugDrawer>,
            from: &btVector3,
            to: &btVector3,
            color: &btVector3,
        );
        unsafe fn DebugDrawer_drawContactPoint(
            drawer: Pin<&mut DebugDrawer>,
            pointOnB: &btVector3,
            normalOnB: &btVector3,
            distance: f32,
            lifeTime: i32,
            color: &btVector3,
        );
        unsafe fn DebugDrawer_reportErrorWarning(
            drawer: Pin<&mut DebugDrawer>,
            warningString: *const c_char,
        );
        unsafe fn DebugDrawer_draw3dText(
            drawer: Pin<&mut DebugDrawer>,
            location: &btVector3,
            textString: *const c_char,
        );
        unsafe fn DebugDrawer_setDebugMode(drawer: Pin<&mut DebugDrawer>, debugMode: i32);
        unsafe fn DebugDrawer_getDebugMode(drawer: Pin<&mut DebugDrawer>) -> i32;

        unsafe fn btVector3_new() -> UniquePtr<btVector3>;
        unsafe fn btVector3_new1(x: f32, y: f32, z: f32) -> UniquePtr<btVector3>;
        unsafe fn btVector3_length(v: &btVector3) -> f32;
        unsafe fn btVector3_x(v: &btVector3) -> f32;
        unsafe fn btVector3_y(v: &btVector3) -> f32;
        unsafe fn btVector3_z(v: &btVector3) -> f32;
        unsafe fn btVector3_setX(v: Pin<&mut btVector3>, x: f32);
        unsafe fn btVector3_setY(v: Pin<&mut btVector3>, y: f32);
        unsafe fn btVector3_setZ(v: Pin<&mut btVector3>, z: f32);
        unsafe fn btVector3_setValue(v: Pin<&mut btVector3>, x: f32, y: f32, z: f32);
        unsafe fn btVector3_normalize(v: Pin<&mut btVector3>);
        unsafe fn btVector3_rotate(
            v: &btVector3,
            wAxis: &btVector3,
            angle: f32,
        ) -> UniquePtr<btVector3>;
        unsafe fn btVector3_dot(v: &btVector3, other: &btVector3) -> f32;
        unsafe fn btVector3_mul(v: &btVector3, s: f32) -> UniquePtr<btVector3>;
        unsafe fn btVector3_add(v: &btVector3, other: &btVector3) -> UniquePtr<btVector3>;
        unsafe fn btVector3_sub(v: &btVector3, other: &btVector3) -> UniquePtr<btVector3>;

        unsafe fn btVector4_new() -> UniquePtr<btVector4>;
        unsafe fn btVector4_new1(x: f32, y: f32, z: f32, w: f32) -> UniquePtr<btVector4>;
        unsafe fn btVector4_length(v: &btVector4) -> f32;
        unsafe fn btVector4_x(v: &btVector4) -> f32;
        unsafe fn btVector4_y(v: &btVector4) -> f32;
        unsafe fn btVector4_z(v: &btVector4) -> f32;
        unsafe fn btVector4_w(v: &btVector4) -> f32;
        unsafe fn btVector4_setX(v: Pin<&mut btVector4>, x: f32);
        unsafe fn btVector4_setY(v: Pin<&mut btVector4>, y: f32);
        unsafe fn btVector4_setZ(v: Pin<&mut btVector4>, z: f32);
        unsafe fn btVector4_setValue(v: Pin<&mut btVector4>, x: f32, y: f32, z: f32, w: f32);
        unsafe fn btVector4_normalize(v: Pin<&mut btVector4>);
        unsafe fn btVector4_rotate(
            v: &btVector4,
            wAxis: &btVector3,
            angle: f32,
        ) -> UniquePtr<btVector3>;
        unsafe fn btVector4_dot(v: &btVector4, other: &btVector4) -> f32;
        unsafe fn btVector4_mul(v: &btVector4, s: f32) -> UniquePtr<btVector3>;
        unsafe fn btVector4_add(v: &btVector4, other: &btVector3) -> UniquePtr<btVector3>;
        unsafe fn btVector4_sub(v: &btVector4, other: &btVector3) -> UniquePtr<btVector3>;

        unsafe fn btQuadWord_x(v: &btQuadWord) -> f32;
        unsafe fn btQuadWord_y(v: &btQuadWord) -> f32;
        unsafe fn btQuadWord_z(v: &btQuadWord) -> f32;
        unsafe fn btQuadWord_w(v: &btQuadWord) -> f32;
        unsafe fn btQuadWord_setX(v: Pin<&mut btQuadWord>, x: f32);
        unsafe fn btQuadWord_setY(v: Pin<&mut btQuadWord>, y: f32);
        unsafe fn btQuadWord_setZ(v: Pin<&mut btQuadWord>, z: f32);
        unsafe fn btQuadWord_setW(v: Pin<&mut btQuadWord>, w: f32);
    }
}

#[cfg(test)]
mod tests {
    use std::ffi::c_char;

    use super::*;

    #[test]
    fn simple_drawer() {
        let draw_line = |from: &ffi::btVector3, _to: &ffi::btVector3, _color: &ffi::btVector3| {
            println!("Drawing line");
            unsafe {
                let a = ffi::btVector3_length(from);
                println!("{}", a)
            }
        };
        let draw_contact_point = |_point_on_b: &ffi::btVector3,
                                  _normal_on_b: &ffi::btVector3,
                                  _distance: f32,
                                  _life_time: i32,
                                  _color: &ffi::btVector3| {};
        let report_error_warning = |_warning_string: *const c_char| {};
        let draw_3d_text = |_location: &ffi::btVector3, _text_string: *const c_char| {};
        let set_debug_mode = |_debug_mode: i32| {};
        let get_debug_mode = || 0;

        let mut drawer = unsafe {
            ffi::DebugDrawer_new(
                draw_line,
                draw_contact_point,
                report_error_warning,
                draw_3d_text,
                set_debug_mode,
                get_debug_mode,
            )
        };

        unsafe {
            ffi::DebugDrawer_drawLine(
                drawer.pin_mut(),
                &ffi::btVector3_new1(0.0, 0.0, 0.0),
                &ffi::btVector3_new1(1.0, 1.0, 1.0),
                &ffi::btVector3_new1(1.0, 0.0, 0.0),
            );
        }
    }
}
