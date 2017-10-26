#ifndef PHYSICBODY_H
#define PHYSICBODY_H

#include <Box2D/Box2D.h>

class PhysicBody{
    public:
        virtual ~PhysicBody(){}
        virtual int   Inicialize(b2Vec2 pos, b2Vec2 tam) = 0;
        virtual b2Vec2 GetPosition() = 0;
        virtual b2Vec2 GetLinearVelocity() = 0;
        virtual float  GetRotation() = 0;
		virtual int    GetId() = 0;
        virtual void   SetFixedRotation(bool fixed) = 0;
        virtual void   SetRotation(float angle) = 0;
		virtual void   SetAngularVelocity(float imp) = 0;
        virtual void   SetLinearVelocity(b2Vec2 vel) = 0;
        virtual void   SetPosition(b2Vec2 pos) = 0;
        virtual void   DestroyFixtures() = 0;
        virtual void   SetCategory(uint16 i) = 0;
        virtual void   SetGravity(float gr) = 0;
        virtual void   SetUserData(int i) = 0;
        virtual void   SetMask(uint16 i) = 0;
        virtual void   Catch(int id) = 0;
        virtual void   Release() = 0;
        virtual b2Body* GetBody();

    protected:
        virtual void   InitFixtures(b2Vec2 tam) = 0;
		virtual void   InitBody(b2Vec2 pos,b2Vec2 tam) = 0;
        virtual void   DestroyBody() = 0;
        int     GenerateId();
        b2Body* GetBodyWithId(int id);
        b2Vec2  DefGetPosition();
        b2Vec2  DefGetLinearVelocity();
        void    DefSetFixedRotation(bool fixed);
        float   DefGetRotation();
        int     DefGetId();
        void    DefSetRotation(float angle);
        void    DefSetGravity(float gr);
        void    DefSetPosition(b2Vec2 pos);
		void    DefSetAngularVelocity(float imp);
		void    DefSetLinearVelocity(b2Vec2 vel);
        void    DefSetCategory(uint16 i);
        void    DefSetUserData(int i);
        void    DefSetMask(uint16 i);
        void    DefCatch(int id);
        void    DefRelease();


        b2World         *m_pWorld;
        b2Body          *m_pBody;
        b2Fixture       *m_fixture;
        int              m_bodyId;
        uint16           m_category;
        int              m_userData;
        uint16           m_mask;
    private:
        static  int      c_id;
};

#endif


