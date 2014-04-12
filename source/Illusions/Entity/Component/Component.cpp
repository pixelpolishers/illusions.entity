/**
 * This file is part of the Entity framework of the Illusions engine
 *
 * @copyright 2008-2014 Pixel Polishers (http://www.pixelpolishers.com)
 */

#include "Illusions/Entity/PrecompiledHeader.hpp"
#include "Illusions/Entity/Entity/IEntity.hpp"
#include "Illusions/Entity/Component/IComponent.hpp"
#include "Illusions/Entity/Component/Component.hpp"

namespace Illusions
{
    namespace Entity
    {
        Component::Component()
            : m_entity(nullptr)
        {
        }

        Component::~Component()
        {
            if (m_entity != nullptr)
            {
                m_entity->removeComponent(this);
                m_entity = nullptr;
            }
        }

        IEntity* Component::getEntity() const
        {
            return m_entity;
        }

        void Component::setEntity(IEntity* entity)
        {
            if (m_entity != entity)
            {
                if (m_entity != nullptr)
                {
                    m_entity->removeComponent(this);
                }

                m_entity = entity;

                if (m_entity != nullptr)
                {
                    m_entity->addComponent(this);
                }
            }
        }

        void Component::update(float deltaTime)
        {
        }
    }
}
