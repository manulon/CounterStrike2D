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

short Entity::getId() const {
    return id;
}

Entity::~Entity() { }

/*void Entity::moveToWorld(std::unique_ptr<Entity> &&entity) {
    world.spawnEntity(std::move(entity));
}*/

/*std::unique_ptr<Entity> Entity::retrieveFromWorld() {
    return world.retrieveSpawnedEntity(*this);
}*/

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

void Entity::attachToWorld(b2BodyDef &bodyDef, Entity &context) {
    world.createBody(bodyDef, context);
}

void Entity::attachToWorld(b2BodyDef &bodyDef, 
                  const b2Shape &shape, float density) {
    body = world.createBody(&bodyDef); 
    bindFixture(shape, density);
    detached = false;
}

void Entity::attachToWorld(b2BodyDef &bodyDef, 
				  const b2FixtureDef &fixtureDef) {
    body = world.createBody(&bodyDef); 
    bindFixture(fixtureDef);
    detached = false;
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

Entity& Entity::clone(const Entity &other) {
    if (this == &other) return *this;
    body = other.body;
    //world = other.world; //MISMO PROBLEMA QUE EN LOADER
    detached = other.detached;
    return *this;
}

void Entity::setBody(b2Body &body) {
    this->body = &body;
    detached = false;
}

World& Entity::getWorld() {
    return world;
}

