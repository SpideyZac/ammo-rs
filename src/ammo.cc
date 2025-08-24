#include "ammo-rs/include/ammo.h"
#include "ammo-rs/src/lib.rs.h"

namespace ammo {
DebugDrawer::DebugDrawer(
    rust::Fn<void(const btVector3 &, const btVector3 &, const btVector3 &)>
        drawLine,
    rust::Fn<void(const btVector3 &, const btVector3 &, float, std::int32_t,
                  const btVector3 &)>
        drawContactPoint,
    rust::Fn<void(const char *)> reportErrorWarning,
    rust::Fn<void(const btVector3 &, const char *)> draw3dText,
    rust::Fn<void(std::int32_t)> setDebugMode,
    rust::Fn<std::int32_t()> getDebugMode)
    : m_drawLine(drawLine), m_drawContactPoint(drawContactPoint),
      m_reportErrorWarning(reportErrorWarning), m_draw3dText(draw3dText),
      m_setDebugMode(setDebugMode), m_getDebugMode(getDebugMode) {}
void DebugDrawer::drawLine(const btVector3 &from, const btVector3 &to,
                           const btVector3 &color) {
  m_drawLine(from, to, color);
}
void DebugDrawer::drawContactPoint(const btVector3 &pointOnB,
                                   const btVector3 &normalOnB, float distance,
                                   std::int32_t lifeTime,
                                   const btVector3 &color) {
  m_drawContactPoint(pointOnB, normalOnB, distance, lifeTime, color);
}
void DebugDrawer::reportErrorWarning(const char *warningString) {
  m_reportErrorWarning(warningString);
}
void DebugDrawer::draw3dText(const btVector3 &location,
                             const char *textString) {
  m_draw3dText(location, textString);
}
void DebugDrawer::setDebugMode(std::int32_t debugMode) {
  m_setDebugMode(debugMode);
}
std::int32_t DebugDrawer::getDebugMode() const { return m_getDebugMode(); }

std::unique_ptr<DebugDrawer> DebugDrawer_new(
    rust::Fn<void(const btVector3 &, const btVector3 &, const btVector3 &)>
        drawLine,
    rust::Fn<void(const btVector3 &, const btVector3 &, float, std::int32_t,
                  const btVector3 &)>
        drawContactPoint,
    rust::Fn<void(const char *)> reportErrorWarning,
    rust::Fn<void(const btVector3 &, const char *)> draw3dText,
    rust::Fn<void(std::int32_t)> setDebugMode,
    rust::Fn<std::int32_t()> getDebugMode) {
  return std::make_unique<DebugDrawer>(drawLine, drawContactPoint,
                                       reportErrorWarning, draw3dText,
                                       setDebugMode, getDebugMode);
}
void DebugDrawer_drawLine(DebugDrawer &drawer, const btVector3 &from,
                          const btVector3 &to, const btVector3 &color) {
  drawer.drawLine(from, to, color);
}
void DebugDrawer_drawContactPoint(DebugDrawer &drawer,
                                  const btVector3 &pointOnB,
                                  const btVector3 &normalOnB, float distance,
                                  std::int32_t lifeTime,
                                  const btVector3 &color) {
  drawer.drawContactPoint(pointOnB, normalOnB, distance, lifeTime, color);
}
void DebugDrawer_reportErrorWarning(DebugDrawer &drawer,
                                    const char *warningString) {
  drawer.reportErrorWarning(warningString);
}
void DebugDrawer_draw3dText(DebugDrawer &drawer, const btVector3 &location,
                            const char *textString) {
  drawer.draw3dText(location, textString);
}
void DebugDrawer_setDebugMode(DebugDrawer &drawer, std::int32_t debugMode) {
  drawer.setDebugMode(debugMode);
}
std::int32_t DebugDrawer_getDebugMode(DebugDrawer &drawer) {
  return drawer.getDebugMode();
}

std::unique_ptr<btVector3> btVector3_new() {
  return std::make_unique<btVector3>();
}
std::unique_ptr<btVector3> btVector3_new1(float x, float y, float z) {
  return std::make_unique<btVector3>(x, y, z);
}
float btVector3_length(const btVector3 &vec) { return vec.length(); }
float btVector3_x(const btVector3 &vec) { return vec.x(); }
float btVector3_y(const btVector3 &vec) { return vec.y(); }
float btVector3_z(const btVector3 &vec) { return vec.z(); }
void btVector3_setX(btVector3 &vec, float x) { vec.setX(x); }
void btVector3_setY(btVector3 &vec, float y) { vec.setY(y); }
void btVector3_setZ(btVector3 &vec, float z) { vec.setZ(z); }
void btVector3_setValue(btVector3 &vec, float x, float y, float z) {
  vec.setValue(x, y, z);
}
void btVector3_normalize(btVector3 &vec) { vec.normalize(); }
std::unique_ptr<btVector3>
btVector3_rotate(const btVector3 &vec, const btVector3 &wAxis, float angle) {
  return std::make_unique<btVector3>(vec.rotate(wAxis, angle));
}
float btVector3_dot(const btVector3 &vec, const btVector3 &v) {
  return vec.dot(v);
}
std::unique_ptr<btVector3> btVector3_mul(const btVector3 &vec, float s) {
  return std::make_unique<btVector3>(vec * s);
}
std::unique_ptr<btVector3> btVector3_add(const btVector3 &vec,
                                         const btVector3 &v) {
  return std::make_unique<btVector3>(vec + v);
}
std::unique_ptr<btVector3> btVector3_sub(const btVector3 &vec,
                                         const btVector3 &v) {
  return std::make_unique<btVector3>(vec - v);
}
} // namespace ammo
