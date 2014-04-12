/**
 * This file is part of the Entity framework of the Illusions engine
 *
 * @copyright 2008-2014 Pixel Polishers (http://www.pixelpolishers.com)
 */

#include "Illusions/Entity/PrecompiledHeader.hpp"
#include "Illusions/Entity/Entity/IEntity.hpp"
#include "Illusions/Entity/Entity/Entity.hpp"
#include "Illusions/Entity/Component/IComponent.hpp"

namespace Illusions
{
    namespace Entity
    {
        Entity::Entity()
            : m_active(false), m_parent(nullptr)
        {
        }

        Entity::~Entity()
        {
            if (m_parent != nullptr)
            {
                m_parent->removeChild(this);
                m_parent = nullptr;
            }
        }

        bool Entity::getActive() const
        {
            return m_active;
        }

        void Entity::setActive(bool active)
        {
            m_active = active;
        }

        void Entity::addChild(IEntity* entity)
        {
            if (std::find(m_children.begin(), m_children.end(), entity) == m_children.end())
            {
                m_children.push_back(entity);

                entity->setParent(this);
            }
        }

        IEntity::EntityCollection Entity::getChildren() const
        {
            return m_children;
        }

        void Entity::removeChild(IEntity* entity)
        {
            EntityCollection::iterator it = std::find(m_children.begin(), m_children.end(), entity);
            if (it != m_children.end())
            {
                m_children.erase(it);

                entity->setParent(nullptr);
            }
        }

        IEntity* Entity::getParent() const
        {
            return m_parent;
        }

        IEntity* Entity::getParentRoot() const
        {
            IEntity* result = m_parent;

            while (result != nullptr)
            {
                result = result->getParent();
            }

            return result;
        }

        void Entity::setParent(IEntity* entity)
        {
            if (m_parent != entity)
            {
                if (m_parent != nullptr)
                {
                    m_parent->removeChild(this);
                }

                m_parent = entity;

                if (m_parent != nullptr)
                {
                    m_parent->addChild(this);
                }
            }
        }

        void Entity::addComponent(IComponent* component)
        {
            if (std::find(m_components.begin(), m_components.end(), component) == m_components.end())
            {
                m_components.push_back(component);

                component->setEntity(this);
            }
        }

        bool Entity::hasComponent(IComponent* component) const
        {
            return std::find(m_components.begin(), m_components.end(), component) != m_components.end();
        }

        void Entity::removeComponent(IComponent* component)
        {
            ComponentCollection::iterator it = std::find(m_components.begin(), m_components.end(), component);
            if (it != m_components.end())
            {
                m_components.erase(it);

                component->setEntity(nullptr);
            }
        }

        IEntity::ComponentCollection Entity::getComponents() const
        {
            return m_components;
        }
    }
}
