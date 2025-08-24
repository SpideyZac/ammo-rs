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
} // namespace ammo
