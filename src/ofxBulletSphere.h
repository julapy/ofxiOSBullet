//
//  ofxBulletSphere.h
//  emptyExample
//
//  Created by Lukasz Karluk on 18/12/12.
//
//

#pragma once

#include "ofMain.h"

class btDynamicsWorld;
class btSphereShape;
class btRigidBody;

class ofxBulletSphere {
    
public:
    
    ofxBulletSphere();
    ~ofxBulletSphere();

    virtual void destroy();
    virtual void setup(btDynamicsWorld * world, float radius, float mass);
    virtual void update();
    virtual void draw();
    
    virtual void setPosition(ofPoint position);
    virtual void setPosition(float x, float y, float z);

    btDynamicsWorld * world;
    btSphereShape * shape;
    btRigidBody * rigidBody;
    
    ofMatrix4x4 matrix;
};