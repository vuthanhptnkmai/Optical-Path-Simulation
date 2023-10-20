#pragma once

// Note: this include may be not necessary in our code right now
#include <stdexcept> // for std::runtime_error
#include <memory>

#include "ray.h"
#include "../utils/vec3.h"

template<typename T, typename U>
class OpticalSurface {
protected:
    vec3<T> position;   // position or center of the optical surface
    vec3<T> normal;     // normal or principal axis of the optical surface

public:
    OpticalSurface(const vec3<T>& position, const vec3<T>& normal) : position(position), normal(normal) {}
    virtual ~OpticalSurface() = default;

    virtual vec3<T> getIntersectionPoint(const Ray<T, U>& ray) const = 0; 
    virtual bool intersects(const Ray<T, U>& ray) const = 0;

    vec3<T> getPosition() const { return position; }
    vec3<T> getNormal() const { return normal; }
};

template<typename T, typename U>
class PlanarSurface : public OpticalSurface<T, U> {
public:
    PlanarSurface(const vec3<T>& position, const vec3<T>& normal) : OpticalSurface<T, U>(position, normal) {}

    vec3<T> getIntersectionPoint(const Ray<T, U>& ray) const override;
    virtual bool intersects(const Ray<T, U>& ray) const override = 0;
};

template<typename T, typename U>
vec3<T> PlanarSurface<T, U>::getIntersectionPoint(const Ray<T, U>& ray) const {
    T intersectionDistance = (this->position - ray.getPosition()).dot(this->normal) / ray.getDirection().dot(this->normal);
    return ray.getPosition() + intersectionDistance * ray.getDirection();
}

// Extensions 

template<typename T, typename U>
class SphericalSurface : public OpticalSurface<T, U> {
protected:
    T radius;  // radius of the spherical surface. positive for convex and negative for concave.

public:
    SphericalSurface(const vec3<T>& position, const vec3<T>& normal, T radius)
        : OpticalSurface<T, U>(position, normal), radius(radius) {}

    // additional methods for SphericalSurface can be added here...
};
