#include "PhysicBody/PhysicBody.h"
#include "World.h"

int PhysicBody::c_id= -1;
b2Vec2 PhysicBody::DefGetPosition(){
	return m_pBody->GetPosition();
}
b2Vec2 PhysicBody::DefGetLinearVelocity(){
	return m_pBody->GetLinearVelocity();
}
float PhysicBody::DefGetRotation(){
	return m_pBody->GetAngle();
}
int PhysicBody::DefGetId(){
	return m_bodyId;
}
void  PhysicBody::DefSetFixedRotation(bool fixed){
    m_pBody->SetFixedRotation(fixed);
}
void PhysicBody::DefSetRotation(float angle){
    m_pBody->SetTransform( m_pBody->GetPosition(),angle);
}
void   PhysicBody::DefSetPosition(b2Vec2 pos){
	m_pBody->SetTransform(pos,m_pBody->GetAngle());
}
void   PhysicBody::DefSetAngularVelocity(float vel){
	m_pBody->ApplyAngularImpulse(vel);
}
void   PhysicBody::DefSetLinearVelocity(b2Vec2 vel){
	m_pBody->SetLinearVelocity(vel);
}
void PhysicBody::DefSetCategory(uint16 i){
	m_category = i;
}
void PhysicBody::DefSetGravity(float gr){
	m_pBody->SetGravityScale(gr);
}
void PhysicBody::DefSetUserData(int i){
	m_userData = i;
}
void PhysicBody::DefSetMask(uint16 i){
	m_mask = i;
}
void PhysicBody::DefCatch(int id){}
void PhysicBody::DefRelease(){}


int PhysicBody::GenerateId(){
	c_id++;
	return c_id;
}

b2Body* PhysicBody:: GetBody(){
    return m_pBody;
}
b2Body* PhysicBody::GetBodyWithId(int id){
	m_pWorld = World::Inst()->GetWorld();
	for ( b2Body* b = m_pWorld->GetBodyList(); b; b = b->GetNext()){
        if((int)b->GetUserData() == id){
            return b;
        }
    }
}
