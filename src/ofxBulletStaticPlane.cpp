//
//  ofxBulletStaticPlane.cpp
//  emptyExample
//
//  Created by Lukasz Karluk on 18/12/12.
//
//

#include "ofxBulletStaticPlane.h"
#include "btBulletDynamicsCommon.h"

ofxBulletStaticPlane::ofxBulletStaticPlane() {
    world = NULL;
    shape = NULL;
    rigidBody = NULL;
}

ofxBulletStaticPlane::~ofxBulletStaticPlane() {
    destroy();
}

void ofxBulletStaticPlane::destroy() {
    if(rigidBody != NULL) {
        world->removeRigidBody(rigidBody);
        delete (btDefaultMotionState *)rigidBody->getMotionState();
        delete rigidBody;
        rigidBody = NULL;
    }
    
    if(shape != NULL) {
        delete shape;
        shape = NULL;
    }
}

void ofxBulletStaticPlane::setup(btDynamicsWorld * world, ofPoint planePosition, ofPoint planeNormal, float planeConstant) {
    destroy();
    
    this->world = world;
    
    shape = new btStaticPlaneShape(btVector3(planeNormal.x, planeNormal.y, planeNormal.z), planeConstant);
    
    btScalar mass = 0;
    btQuaternion quat(0, 0, 0, 1);
    btVector3 position(planePosition.x, planePosition.y, planePosition.z);
    btTransform transform(quat, position);
    btVector3 inertia(0, 0, 0);
    
    btDefaultMotionState * motionState = new btDefaultMotionState(transform);
    btRigidBody::btRigidBodyConstructionInfo rigidBodyCI(mass, motionState, shape, inertia);
    
    rigidBody = new btRigidBody(rigidBodyCI);
    world->addRigidBody(rigidBody);
}

void ofxBulletStaticPlane::setupFloor(btDynamicsWorld * world, ofPoint planePosition) {
    setup(world, planePosition, ofPoint(0, -1, 0));
}

void ofxBulletStaticPlane::setupCeiling(btDynamicsWorld * world, ofPoint planePosition) {
    setup(world, planePosition, ofPoint(0, 1, 0));
}

void ofxBulletStaticPlane::update() {
    //
}

void ofxBulletStaticPlane::draw() {
    //
}
