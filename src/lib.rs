#[allow(dead_code)]
#[cxx::bridge(namespace = "ammo")]
mod ffi {
    extern "Rust" {}

    unsafe extern "C++" {
        include!("ammo-rs/include/ammo.h");

        type DebugDrawer;
        type btVector3;

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
    }
}

#[cfg(test)]
mod tests {
    use super::*;
}
