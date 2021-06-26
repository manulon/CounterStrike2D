#include "Entity.h"
#include "World.h"

Entity::Entity() : 
    body(nullptr), 
    world(nullptr) { }

Entity::Entity(Entity &&other) : 
    body(other.body),
    world(other.world) {
    other.body = nullptr;
    other.world = nullptr;
}

Entity::~Entity() { }

void Entity::init(World &world, b2BodyDef &bodyDef, 
                          const b2Shape &shape, float density) {
    this->world = &world;
    body = world.createBody(&bodyDef); 
    bindFixtureToEntity(shape, density);
}

void Entity::init(World &world, b2BodyDef &bodyDef, 
						  const b2FixtureDef &fixtureDef) {
    this->world = &world;
    body = world.createBody(&bodyDef); 
    bindFixtureToEntity(fixtureDef);
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

float Entity::radiansToAngle(float radians) const {
    return (fmod(radians, (2 * b2_pi)) * 180) / b2_pi;
}

void Entity::bindFixtureToEntity(const b2Shape &shape, float density) {
    body->CreateFixture(&shape, density);
}

void Entity::bindFixtureToEntity(const b2FixtureDef &fixtureDef) {
    body->CreateFixture(&fixtureDef);
}

std::ostream& operator<<(std::ostream &os, const Entity &obj) {
    float position_x = obj.getPositionX();
    float position_y = obj.getPositionY();
    float angle = obj.getAngle();
    char buffer[100];
    snprintf(buffer, sizeof(buffer), "%4.2f %4.2f %4.2f", position_x, position_y, angle);
    os << buffer;
    return os;
}

void Entity::destroy() {
    world->destroy(*body);
}
