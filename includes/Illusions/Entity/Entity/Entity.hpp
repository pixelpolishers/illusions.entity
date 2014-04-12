/**
 * This file is part of the Entity framework of the Illusions engine
 *
 * @copyright 2008-2014 Pixel Polishers (http://www.pixelpolishers.com)
 */

#pragma once

namespace Illusions
{
    namespace Entity
    {
        class IComponent;
        class IEntity;

        /**
         * The representation of a basic entity.
         */
        class Entity: public IEntity
        {
        public:
            /**
             * Initializes a new instance of this class.
             */
            Entity();

            /**
             * Cleans up all the resources used by this class.
             */
            virtual ~Entity();

            /**
             * Gets the active flag for this entity.
             *
             * @return Returns true when this entity is active; false otherwise.
             */
            virtual bool getActive() const;

            /**
             * Activates or deactivates the entity.
             *
             * @param[in] active The active flag to set.
             */
            virtual void setActive(bool active);

            /**
             * Adds a child entity to the hierarchy of this entity.
             *
             * @param[in] entity The entity to add as a child.
             */
            virtual void addChild(IEntity* entity);

            /**
             * Gets the children for this entity.
             *
             * @param[in] entity The entity to add as a child.
             */
            virtual EntityCollection getChildren() const;

            /**
             * Removes a child entity from the hierarchy of this entity.
             *
             * @param[in] entity The entity to add as a child.
             */
            virtual void removeChild(IEntity* entity);

            /**
              * Gets the parent of this entity.
              *
              * @return Returns an instance of IEntity or nullptr if there is no entity.
              */
            virtual IEntity* getParent() const;

            /**
             * Gets the root of the hierarchy for this entity.
             *
             * @return Returns an instance of IEntity or nullptr if there is no parent.
             */
            virtual IEntity* getParentRoot() const;

            /**
             * Sest the parent of this entity.
             *
             * @param[in] entity The entity to set as a parent.
             */
            virtual void setParent(IEntity* entity);

            /**
             * Adds a component to this entity.
             *
             * @param[in] component The component to add.
             */
            virtual void addComponent(IComponent* component);

            /**
             * Checks if this entity has the given component.
             *
             * @param[in] component The component to check.
             * @return Returns true when the entity has the given component; false otherwise.
             */
            virtual bool hasComponent(IComponent* component) const;

            /**
             * Removes the given component from this entity.
             *
             * @param[in] component The component to remove.
             */
            virtual void removeComponent(IComponent* component);

            /**
             * Gets the components within this entity.
             *
             * @return Returns a component collection.
             */
            virtual ComponentCollection getComponents() const;

            /**
             * Gets the first available component of the given type.
             *
             * @return Returns the instance of the component or nullptr when no component exists.
             */
            template <class T> T* getFirstComponent() const
            {
                for (ComponentCollection::const_iterator it = m_components.begin(); it != m_components.end(); ++it)
                {
                    T* casted = (T*)(*it);
                    if (casted != nullptr)
                    {
                        return casted;
                    }
                }
                return nullptr;
            }

        private:
            /**
             * A flag that indicates whether or not the entity is active.
             */
            bool m_active;

            /**
             * The parent entity of this entity.
             */
            IEntity* m_parent;

            /**
             * A list with all child entities of this entity.
             */
            std::vector<IEntity*> m_children;

            /**
             * The list with components for this entity.
             */
            std::vector<IComponent*> m_components;
        };
    }
}
