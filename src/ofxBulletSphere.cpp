//
//  ofxBulletSphere.cpp
//  emptyExample
//
//  Created by Lukasz Karluk on 18/12/12.
//
//

#include "ofxBulletSphere.h"
#include "btBulletDynamicsCommon.h"

ofxBulletSphere::ofxBulletSphere() {
    world = NULL;
    shape = NULL;
    rigidBody = NULL;
}

ofxBulletSphere::~ofxBulletSphere() {
    destroy();
}

void ofxBulletSphere::destroy() {
    if(rigidBody != NULL) {
        world->removeRigidBody( rigidBody );
        delete (btDefaultMotionState *)rigidBody->getMotionState();
        delete rigidBody;
        rigidBody = NULL;
    }
    
    if(shape != NULL) {
        delete shape;
        shape = NULL;
    }
}

void ofxBulletSphere::setup(btDynamicsWorld * world, float radius, float mass) {
    destroy();
    
    this->world = world;
    
    btVector3 inertia(0, 0, 0);
    
    btTransform transform;
    transform.setFromOpenGLMatrix(matrix.getPtr());
    
    shape = new btSphereShape(radius);
    
    btDefaultMotionState * motionState = new btDefaultMotionState(transform);
    shape->calculateLocalInertia(mass, inertia);
    
    btRigidBody::btRigidBodyConstructionInfo rigidBodyCI(mass, motionState, shape, inertia);
    rigidBody = new btRigidBody(rigidBodyCI);
    
    world->addRigidBody(rigidBody);
}

void ofxBulletSphere::update() {
    float mat[16];
    btTransform trans;
    btMotionState * motionState = rigidBody->getMotionState();
    motionState->getWorldTransform(trans);
    trans.getOpenGLMatrix(&mat[0]);
    matrix.set(&mat[0]);
}

void ofxBulletSphere::draw() {
    ofPushMatrix();
    ofMultMatrix(matrix);
    ofSphere(0, 0, 0, shape->getRadius());
    ofPopMatrix();
}

void ofxBulletSphere::setPosition(ofPoint position) {
    setPosition(position.x, position.y, position.z);
}

void ofxBulletSphere::setPosition(float x, float y, float z) {
    matrix.setTranslation(x, y, z);
    if(rigidBody == NULL) {
        return;
    }
    btTransform trans;
    trans.setFromOpenGLMatrix(matrix.getPtr());
    btMotionState * motionState = rigidBody->getMotionState();
    motionState->setWorldTransform(trans);    
}


