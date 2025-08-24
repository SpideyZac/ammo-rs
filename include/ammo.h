#pragma once
#include <memory>

#include "BulletCollision/CollisionDispatch/btGhostObject.h"
#include "BulletCollision/CollisionShapes/btConvexPolyhedron.h"
#include "BulletCollision/CollisionShapes/btHeightfieldTerrainShape.h"
#include "BulletCollision/CollisionShapes/btShapeHull.h"
#include "BulletCollision/Gimpact/btGImpactCollisionAlgorithm.h"
#include "BulletCollision/Gimpact/btGImpactShape.h"
#include "BulletDynamics/Character/btKinematicCharacterController.h"
#include "BulletSoftBody/btDefaultSoftBodySolver.h"
#include "BulletSoftBody/btSoftBody.h"
#include "BulletSoftBody/btSoftBodyHelpers.h"
#include "BulletSoftBody/btSoftBodyRigidBodyCollisionConfiguration.h"
#include "BulletSoftBody/btSoftRigidDynamicsWorld.h"
#include "btBulletDynamicsCommon.h"

#include "rust/cxx.h"

namespace ammo {
using ::btVector3;

class DebugDrawer : public btIDebugDraw {
private:
  rust::Fn<void(const btVector3 &, const btVector3 &, const btVector3 &)>
      m_drawLine;
  rust::Fn<void(const btVector3 &, const btVector3 &, float, std::int32_t,
                const btVector3 &)>
      m_drawContactPoint;
  rust::Fn<void(const char *)> m_reportErrorWarning;
  rust::Fn<void(const btVector3 &, const char *)> m_draw3dText;
  rust::Fn<void(std::int32_t)> m_setDebugMode;
  rust::Fn<std::int32_t()> m_getDebugMode;

public:
  DebugDrawer(
      rust::Fn<void(const btVector3 &, const btVector3 &, const btVector3 &)>
          drawLine,
      rust::Fn<void(const btVector3 &, const btVector3 &, float, std::int32_t,
                    const btVector3 &)>
          drawContactPoint,
      rust::Fn<void(const char *)> reportErrorWarning,
      rust::Fn<void(const btVector3 &, const char *)> draw3dText,
      rust::Fn<void(std::int32_t)> setDebugMode,
      rust::Fn<std::int32_t()> getDebugMode);
  ~DebugDrawer() override = default;
  void drawLine(const btVector3 &from, const btVector3 &to,
                const btVector3 &color) override;
  void drawContactPoint(const btVector3 &pointOnB, const btVector3 &normalOnB,
                        float distance, std::int32_t lifeTime,
                        const btVector3 &color) override;
  void reportErrorWarning(const char *warningString) override;
  void draw3dText(const btVector3 &location, const char *textString) override;
  void setDebugMode(std::int32_t debugMode) override;
  std::int32_t getDebugMode() const override;
};

std::unique_ptr<DebugDrawer> DebugDrawer_new(
    rust::Fn<void(const btVector3 &, const btVector3 &, const btVector3 &)>
        drawLine,
    rust::Fn<void(const btVector3 &, const btVector3 &, float, std::int32_t,
                  const btVector3 &)>
        drawContactPoint,
    rust::Fn<void(const char *)> reportErrorWarning,
    rust::Fn<void(const btVector3 &, const char *)> draw3dText,
    rust::Fn<void(std::int32_t)> setDebugMode,
    rust::Fn<std::int32_t()> getDebugMode);
void DebugDrawer_drawLine(DebugDrawer &drawer, const btVector3 &from,
                          const btVector3 &to, const btVector3 &color);
void DebugDrawer_drawContactPoint(DebugDrawer &drawer,
                                  const btVector3 &pointOnB,
                                  const btVector3 &normalOnB, float distance,
                                  std::int32_t lifeTime,
                                  const btVector3 &color);
void DebugDrawer_reportErrorWarning(DebugDrawer &drawer,
                                    const char *warningString);
void DebugDrawer_draw3dText(DebugDrawer &drawer, const btVector3 &location,
                            const char *textString);
void DebugDrawer_setDebugMode(DebugDrawer &drawer, std::int32_t debugMode);
std::int32_t DebugDrawer_getDebugMode(DebugDrawer &drawer);

std::unique_ptr<btVector3> btVector3_new();
std::unique_ptr<btVector3> btVector3_new1(float x, float y, float z);
float btVector3_length(const btVector3 &vec);
float btVector3_x(const btVector3 &vec);
float btVector3_y(const btVector3 &vec);
float btVector3_z(const btVector3 &vec);
void btVector3_setX(btVector3 &vec, float x);
void btVector3_setY(btVector3 &vec, float y);
void btVector3_setZ(btVector3 &vec, float z);
void btVector3_setValue(btVector3 &vec, float x, float y, float z);
void btVector3_normalize(btVector3 &vec);
std::unique_ptr<btVector3>
btVector3_rotate(const btVector3 &vec, const btVector3 &wAxis, float angle);
float btVector3_dot(const btVector3 &vec, const btVector3 &v);
std::unique_ptr<btVector3> btVector3_mul(const btVector3 &vec, float s);
std::unique_ptr<btVector3> btVector3_add(const btVector3 &vec,
                                         const btVector3 &v);
std::unique_ptr<btVector3> btVector3_sub(const btVector3 &vec,
                                         const btVector3 &v);
} // namespace ammo
