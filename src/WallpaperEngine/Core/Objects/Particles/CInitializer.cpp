#include "CInitializer.h"

#include "WallpaperEngine/Core/Core.h"
#include "WallpaperEngine/Core/Objects/Particles/Initializers/CLifeTimeRandom.h"
#include "WallpaperEngine/Core/Objects/Particles/Initializers/CSizeRandom.h"
#include "WallpaperEngine/Core/Objects/Particles/Initializers/CRotationRandom.h"
#include "WallpaperEngine/Core/Objects/Particles/Initializers/CVelocityRandom.h"
#include "WallpaperEngine/Core/Objects/Particles/Initializers/CColorRandom.h"
#include "WallpaperEngine/Core/Objects/Particles/Initializers/CAlphaRandom.h"
#include "WallpaperEngine/Core/Objects/Particles/Initializers/CAngularVelocityRandom.h"

using namespace WallpaperEngine::Core::Objects::Particles;

CInitializer* CInitializer::fromJSON (json data)
{
    auto id_it = data.find ("id");
    auto name_it = jsonFindValueRequired(&data, "name", "Particle's initializer must have a name");
    irr::u32 id = ((id_it == data.end ()) ? 0 : (irr::u32) (*id_it));

    if (*name_it == "lifetimerandom")
    {
        return Initializers::CLifeTimeRandom::fromJSON (data, id);
    }
    else if (*name_it == "sizerandom")
    {
        return Initializers::CSizeRandom::fromJSON (data, id);
    }
    else if (*name_it == "rotationrandom")
    {
        return Initializers::CRotationRandom::fromJSON (data, id);
    }
    else if (*name_it == "velocityrandom")
    {
        return Initializers::CVelocityRandom::fromJSON (data, id);
    }
    else if (*name_it == "colorrandom")
    {
        return Initializers::CColorRandom::fromJSON (data, id);
    }
    else if (*name_it == "alpharandom")
    {
        return Initializers::CAlphaRandom::fromJSON (data, id);
    }
    else if (*name_it == "angularvelocityrandom")
    {
        return Initializers::CAngularVelocityRandom::fromJSON (data, id);
    }
    else
    {
        throw std::runtime_error ("Particle's got an unknown initializer");
    }
}


CInitializer::CInitializer (irr::u32 id, std::string name) :
    m_id (id),
    m_name (std::move(name))
{
}


const std::string& CInitializer::getName () const
{
    return this->m_name;
}

const irr::u32 CInitializer::getId () const
{
    return this->m_id;
}