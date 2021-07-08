#include "Entity.h"
#include "World.h"

Entity::Entity(World &world, short id) : 
    body(nullptr), 
    world(world),
    detached(true) , id(id){ }

Entity::Entity(Entity &&other) : 
    body(other.body),
    world(other.world),
    detached(other.detached),
    id(other.id) {
    other.body = nullptr;
    other.detached = true;
    other.id = 0;
}

Entity::~Entity() { }

void Entity::bindFixture(const b2FixtureDef &fixtureDef) {
    body->CreateFixture(&fixtureDef);
}

float Entity::radiansToAngle(float radians) const {
    return (fmod(radians, (2 * b2_pi)) * 180) / b2_pi;
}

void Entity::applyForceToCenter(const b2Vec2 &force, bool wake) {
    body->ApplyForceToCenter(force, wake);
}

void Entity::applyLinearImpulseToCenter(const b2Vec2 &force,
                                bool wake) {
    b2Vec2 position = body->GetPosition();
    body->ApplyLinearImpulse(force, position, wake);
}

float Entity::getPositionX() const {
	return body->GetPosition().x;
}

float Entity::getPositionY() const {
    return body->GetPosition().y;
}

// TODO
// OJO QUE DEVUELVE ANGULOS NEGATIVOS SI HAY UN BUG
// EN ALGUN ANGULO HABRIA QUE REVISAR LA FORMA EN QUE
// BOX 2D CONSIDERA RADIANES Y VER SI ES ESTE EL PROBLEMA
float Entity::getAngle() const {
    float angle = radiansToAngle(body->GetAngle());
    return angle;
}

void Entity::earlyAttachToWorld(b2BodyDef &bodyDef, 
				  const b2FixtureDef &fixtureDef) {
    body = world.createBody(&bodyDef); 
    bindFixture(fixtureDef);
    detached = false;
}

void Entity::setId(short idn){
    id = idn;
}

void Entity::lateAttachToWorld(b2BodyDef &bodyDef, Entity &context) {
    world.createBody(bodyDef, context);
}

void Entity::detachFromWorld() {
    if (!detached) { 
        world.destroyBody(&body);
        detached = true;
    }
}

std::ostream& operator<<(std::ostream &os, const Entity &entity) {
    // TODO
    // CORREGIR FORMATO LUEGO
    float positionX = entity.getPositionX();
    float positionY = entity.getPositionY();
    short id = entity.getId();
    float angle = entity.getAngle();
    char buffer[100];
    snprintf(buffer, sizeof(buffer), "%i %4.2f %4.2f %4.2f", id, positionX, positionY, angle);
    os << buffer;
    return os;
}

bool Entity::isDetached() {
    return detached;
}

void Entity::setTransform(float x, float y, float angle) {
    body->SetTransform(b2Vec2(x, y), angle * b2_pi/180);
}

void Entity::setBody(b2Body &body) {
    this->body = &body;
    detached = false;
}

World& Entity::getWorld() {
    return world;
}

short Entity::getId() const {
    return id;
}

