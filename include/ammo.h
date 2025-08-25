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
using ::btIDebugDraw;
using ::btMatrix3x3;
using ::btMotionState;
using ::btQuadWord;
using ::btQuaternion;
using ::btTransform;
using ::btVector3;
using ::btVector4;

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

std::unique_ptr<btVector4> btVector4_new();
std::unique_ptr<btVector4> btVector4_new1(float x, float y, float z, float w);
float btVector4_length(const btVector4 &vec);
float btVector4_x(const btVector4 &vec);
float btVector4_y(const btVector4 &vec);
float btVector4_z(const btVector4 &vec);
float btVector4_w(const btVector4 &vec);
void btVector4_setX(btVector4 &vec, float x);
void btVector4_setY(btVector4 &vec, float y);
void btVector4_setZ(btVector4 &vec, float z);
void btVector4_setValue(btVector4 &vec, float x, float y, float z, float w);
void btVector4_normalize(btVector4 &vec);
std::unique_ptr<btVector3>
btVector4_rotate(const btVector4 &vec, const btVector3 &wAxis, float angle);
float btVector4_dot(const btVector4 &vec, const btVector4 &v);
std::unique_ptr<btVector3> btVector4_mul(const btVector4 &vec, float s);
std::unique_ptr<btVector3> btVector4_add(const btVector4 &vec,
                                         const btVector3 &v);
std::unique_ptr<btVector3> btVector4_sub(const btVector4 &vec,
                                         const btVector3 &v);

float btQuadWord_x(const btQuadWord &vec);
float btQuadWord_y(const btQuadWord &vec);
float btQuadWord_z(const btQuadWord &vec);
float btQuadWord_w(const btQuadWord &vec);
void btQuadWord_setX(btQuadWord &vec, float x);
void btQuadWord_setY(btQuadWord &vec, float y);
void btQuadWord_setZ(btQuadWord &vec, float z);
void btQuadWord_setW(btQuadWord &vec, float w);

std::unique_ptr<btQuaternion> btQuaternion_new(float x, float y, float z,
                                               float w);
void btQuaternion_setValue(btQuaternion &quat, float x, float y, float z,
                           float w);
void btQuaternion_setEulerZYX(btQuaternion &quat, float z, float y, float x);
void btQuaternion_setRotation(btQuaternion &quat, const btVector3 &axis,
                              float angle);
void btQuaternion_normalize(btQuaternion &quat);
float btQuaternion_length2(const btQuaternion &quat);
float btQuaternion_length(const btQuaternion &quat);
float btQuaternion_dot(const btQuaternion &quat, const btQuaternion &q);
std::unique_ptr<btQuaternion> btQuaternion_normalized(const btQuaternion &quat);
std::unique_ptr<btVector3> btQuaternion_getAxis(const btQuaternion &quat);
std::unique_ptr<btQuaternion> btQuaternion_inverse(const btQuaternion &quat);
float btQuaternion_getAngle(const btQuaternion &quat);
float btQuaternion_getAngleShortestPath(const btQuaternion &quat);
float btQuaternion_angle(const btQuaternion &quat, const btQuaternion &q);
float btQuaternion_angleShortestPath(const btQuaternion &quat,
                                     const btQuaternion &q);
std::unique_ptr<btQuaternion> btQuaternion_add(const btQuaternion &quat,
                                               const btQuaternion &q);
std::unique_ptr<btQuaternion> btQuaternion_sub(const btQuaternion &quat,
                                               const btQuaternion &q);
std::unique_ptr<btQuaternion> btQuaternion_mul(const btQuaternion &quat,
                                               float s);
std::unique_ptr<btQuaternion> btQuaternion_mulq(const btQuaternion &quat,
                                                const btQuaternion &q);
std::unique_ptr<btQuaternion> btQuaternion_div(const btQuaternion &quat,
                                               float s);
float btQuaternion_x(const btQuaternion &quat);
float btQuaternion_y(const btQuaternion &quat);
float btQuaternion_z(const btQuaternion &quat);
float btQuaternion_w(const btQuaternion &quat);
void btQuaternion_setX(btQuaternion &quat, float x);
void btQuaternion_setY(btQuaternion &quat, float y);
void btQuaternion_setZ(btQuaternion &quat, float z);
void btQuaternion_setW(btQuaternion &quat, float w);

void btMatrix3x3_setEulerZYX(btMatrix3x3 &mat, float ex, float ey, float ez);
void btMatrix3x3_getRotation(const btMatrix3x3 &mat, btQuaternion &quat);
std::unique_ptr<btVector3> btMatrix3x3_getRow(const btMatrix3x3 &mat, int y);

std::unique_ptr<btTransform> btTransform_new();
std::unique_ptr<btTransform> btTransform_new1(const btQuaternion &q,
                                              const btVector3 &v);
void btTransform_setIdentity(btTransform &trans);
void btTransform_setOrigin(btTransform &trans, const btVector3 &origin);
void btTransform_setRotation(btTransform &trans, const btQuaternion &rotation);
std::unique_ptr<btVector3> btTransform_getOrigin(const btTransform &trans);
std::unique_ptr<btQuaternion> btTransform_getRotation(const btTransform &trans);
std::unique_ptr<btMatrix3x3> btTransform_getBasis(const btTransform &trans);
void setFromOpenGLMatrix(btTransform &trans, const float *m);
std::unique_ptr<btTransform> btTransform_inverse(const btTransform &trans);
std::unique_ptr<btTransform> btTransform_mul(const btTransform &trans,
                                             const btTransform &t);

class MotionState : public btMotionState {
private:
  rust::Fn<void(btTransform &)> m_getWorldTransform;
  rust::Fn<void(const btTransform &)> m_setWorldTransform;

public:
  MotionState(rust::Fn<void(btTransform &)> getWorldTransform,
              rust::Fn<void(const btTransform &)> setWorldTransform);

  void getWorldTransform(btTransform &worldTrans) const override;
  void setWorldTransform(const btTransform &worldTrans) override;
};

std::unique_ptr<MotionState>
MotionState_new(rust::Fn<void(btTransform &)> getWorldTransform,
                rust::Fn<void(const btTransform &)> setWorldTransform);
void MotionState_getWorldTransform(const MotionState &motionState,
                                   btTransform &worldTrans);
void MotionState_setWorldTransform(MotionState &motionState,
                                   const btTransform &worldTrans);
} // namespace ammo
