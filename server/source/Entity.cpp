#include "Entity.h"
#include "World.h"

Entity::Entity(World &world) : 
    body(nullptr), 
    world(world) { }

Entity::Entity(Entity &&other) : 
    body(other.body),
    world(other.world) {
    other.body = nullptr;
}

Entity::~Entity() { }

void Entity::init(b2BodyDef &bodyDef, 
                  const b2Shape &shape, float density) {
    body = world.createBody(&bodyDef); 
    bindFixture(shape, density);
}

void Entity::init(b2BodyDef &bodyDef, 
				  const b2FixtureDef &fixtureDef) {
    body = world.createBody(&bodyDef); 
    bindFixture(fixtureDef);
}

void Entity::bindFixture(const b2Shape &shape, float density) {
    body->CreateFixture(&shape, density);
}

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

void Entity::destroy() {
    if (body != nullptr) {
        world.destroy(*body);
        body = nullptr;        
    }
}

std::ostream& operator<<(std::ostream &os, const Entity &entity) {
    // TODO
    // CORREGIR FORMATO LUEGO
    float positionX = entity.getPositionX();
    float positionY = entity.getPositionY();
    float angle = entity.getAngle();
    char buffer[100];
    snprintf(buffer, sizeof(buffer), "%4.2f %4.2f %4.2f", positionX, positionY, angle);
    os << buffer;
    return os;
}
