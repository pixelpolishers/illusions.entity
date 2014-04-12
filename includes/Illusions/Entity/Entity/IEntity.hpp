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

        /**
         * The IEntity interface describes an entity.
         */
        class IEntity
        {
        public:
            typedef std::vector<IComponent*> ComponentCollection;
            typedef std::vector<IEntity*> EntityCollection;

            /**
             * Cleans up all the resources used by this class.
             */
            virtual ~IEntity() { }

            /**
             * Gets the active flag for this entity.
             *
             * @return Returns true when this entity is active; false otherwise.
             */
            virtual bool getActive() const = 0;

            /**
             * Activates or deactivates the entity.
             *
             * @param[in] active The active flag to set.
             */
            virtual void setActive(bool active) = 0;

            /**
             * Adds a child entity to the hierarchy of this entity.
             *
             * @param[in] entity The entity to add as a child.
             */
            virtual void addChild(IEntity* entity) = 0;

            /**
             * Gets the children for this entity.
             *
             * @param[in] entity The entity to add as a child.
             */
            virtual EntityCollection getChildren() const = 0;

            /**
             * Removes a child entity from the hierarchy of this entity.
             *
             * @param[in] entity The entity to add as a child.
             */
            virtual void removeChild(IEntity* entity) = 0;

            /**
             * Gets the parent of this entity.
             *
             * @return Returns an instance of IEntity or nullptr if there is no entity.
             */
            virtual IEntity* getParent() const = 0;

            /**
             * Gets the root of the hierarchy for this entity.
             *
             * @return Returns an instance of IEntity or nullptr if there is no parent.
             */
            virtual IEntity* getParentRoot() const = 0;

            /**
             * Sest the parent of this entity.
             *
             * @param[in] entity The entity to set as a parent.
             */
            virtual void setParent(IEntity* entity) = 0;
            
            /**
             * Adds a component to this entity.
             *
             * @param[in] component The component to add.
             */
            virtual void addComponent(IComponent* component) = 0;

            /**
             * Checks if this entity has the given component.
             *
             * @param[in] component The component to check.
             * @return Returns true when the entity has the given component; false otherwise.
             */
            virtual bool hasComponent(IComponent* component) const = 0;

            /**
             * Removes the given component from this entity.
             *
             * @param[in] component The component to remove.
             */
            virtual void removeComponent(IComponent* component) = 0;

            /**
             * Gets the components within this entity.
             *
             * @return Returns a component collection.
             */
            virtual ComponentCollection getComponents() const = 0;
        };
    }
}
