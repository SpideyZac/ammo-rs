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

std::unique_ptr<btVector4> btVector4_new() {
  return std::make_unique<btVector4>();
}
std::unique_ptr<btVector4> btVector4_new1(float x, float y, float z, float w) {
  return std::make_unique<btVector4>(x, y, z, w);
}
float btVector4_length(const btVector4 &vec) { return vec.length(); }
float btVector4_x(const btVector4 &vec) { return vec.x(); }
float btVector4_y(const btVector4 &vec) { return vec.y(); }
float btVector4_z(const btVector4 &vec) { return vec.z(); }
float btVector4_w(const btVector4 &vec) { return vec.w(); }
void btVector4_setX(btVector4 &vec, float x) { vec.setX(x); }
void btVector4_setY(btVector4 &vec, float y) { vec.setY(y); }
void btVector4_setZ(btVector4 &vec, float z) { vec.setZ(z); }
void btVector4_setValue(btVector4 &vec, float x, float y, float z, float w) {
  vec.setValue(x, y, z, w);
}
void btVector4_normalize(btVector4 &vec) { vec.normalize(); }
std::unique_ptr<btVector3>
btVector4_rotate(const btVector4 &vec, const btVector3 &wAxis, float angle) {
  return std::make_unique<btVector3>(vec.rotate(wAxis, angle));
}
float btVector4_dot(const btVector4 &vec, const btVector4 &v) {
  return vec.dot(v);
}
std::unique_ptr<btVector3> btVector4_mul(const btVector4 &vec, float s) {
  return std::make_unique<btVector3>(vec * s);
}
std::unique_ptr<btVector3> btVector4_add(const btVector4 &vec,
                                         const btVector3 &v) {
  return std::make_unique<btVector3>(vec + v);
}
std::unique_ptr<btVector3> btVector4_sub(const btVector4 &vec,
                                         const btVector3 &v) {
  return std::make_unique<btVector3>(vec - v);
}

float btQuadWord_x(const btQuadWord &vec) { return vec.x(); }
float btQuadWord_y(const btQuadWord &vec) { return vec.y(); }
float btQuadWord_z(const btQuadWord &vec) { return vec.z(); }
float btQuadWord_w(const btQuadWord &vec) { return vec.w(); }
void btQuadWord_setX(btQuadWord &vec, float x) { vec.setX(x); }
void btQuadWord_setY(btQuadWord &vec, float y) { vec.setY(y); }
void btQuadWord_setZ(btQuadWord &vec, float z) { vec.setZ(z); }
void btQuadWord_setW(btQuadWord &vec, float w) { vec.setW(w); }

std::unique_ptr<btQuaternion> btQuaternion_new(float x, float y, float z,
                                               float w) {
  return std::make_unique<btQuaternion>(x, y, z, w);
}
void btQuaternion_setValue(btQuaternion &quat, float x, float y, float z,
                           float w) {
  quat.setValue(x, y, z, w);
}
void btQuaternion_setEulerZYX(btQuaternion &quat, float z, float y, float x) {
  quat.setEulerZYX(z, y, x);
}
void btQuaternion_setRotation(btQuaternion &quat, const btVector3 &axis,
                              float angle) {
  quat.setRotation(axis, angle);
}
void btQuaternion_normalize(btQuaternion &quat) { quat.normalize(); }
float btQuaternion_length2(const btQuaternion &quat) { return quat.length2(); }
float btQuaternion_length(const btQuaternion &quat) { return quat.length(); }
float btQuaternion_dot(const btQuaternion &quat, const btQuaternion &q) {
  return quat.dot(q);
}
std::unique_ptr<btQuaternion>
btQuaternion_normalized(const btQuaternion &quat) {
  return std::make_unique<btQuaternion>(quat.normalized());
}
std::unique_ptr<btVector3> btQuaternion_getAxis(const btQuaternion &quat) {
  return std::make_unique<btVector3>(quat.getAxis());
}
std::unique_ptr<btQuaternion> btQuaternion_inverse(const btQuaternion &quat) {
  return std::make_unique<btQuaternion>(quat.inverse());
}
float btQuaternion_getAngle(const btQuaternion &quat) {
  return quat.getAngle();
}
float btQuaternion_getAngleShortestPath(const btQuaternion &quat) {
  return quat.getAngleShortestPath();
}
float btQuaternion_angle(const btQuaternion &quat, const btQuaternion &q) {
  return quat.angle(q);
}
float btQuaternion_angleShortestPath(const btQuaternion &quat,
                                     const btQuaternion &q) {
  return quat.angleShortestPath(q);
}
std::unique_ptr<btQuaternion> btQuaternion_add(const btQuaternion &quat,
                                               const btQuaternion &q) {
  return std::make_unique<btQuaternion>(quat + q);
}
std::unique_ptr<btQuaternion> btQuaternion_sub(const btQuaternion &quat,
                                               const btQuaternion &q) {
  return std::make_unique<btQuaternion>(quat - q);
}
std::unique_ptr<btQuaternion> btQuaternion_mul(const btQuaternion &quat,
                                               float s) {
  return std::make_unique<btQuaternion>(quat * s);
}
std::unique_ptr<btQuaternion> btQuaternion_mulq(const btQuaternion &quat,
                                                const btQuaternion &q) {
  return std::make_unique<btQuaternion>(quat * q);
}
std::unique_ptr<btQuaternion> btQuaternion_div(const btQuaternion &quat,
                                               float s) {
  return std::make_unique<btQuaternion>(quat / s);
}
float btQuaternion_x(const btQuaternion &quat) { return quat.x(); }
float btQuaternion_y(const btQuaternion &quat) { return quat.y(); }
float btQuaternion_z(const btQuaternion &quat) { return quat.z(); }
float btQuaternion_w(const btQuaternion &quat) { return quat.w(); }
void btQuaternion_setX(btQuaternion &quat, float x) { quat.setX(x); }
void btQuaternion_setY(btQuaternion &quat, float y) { quat.setY(y); }
void btQuaternion_setZ(btQuaternion &quat, float z) { quat.setZ(z); }
void btQuaternion_setW(btQuaternion &quat, float w) { quat.setW(w); }
} // namespace ammo