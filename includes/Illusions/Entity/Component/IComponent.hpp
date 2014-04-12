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
        class IEntity;

        /**
         * The IComponent interface describes a component which is part of an entity.
         */
        class IComponent
        {
        public:
            /**
             * Cleans up all the resources used by this class.
             */
            virtual ~IComponent() { }

            /**
             * Gets the entity to which this component belongs to.
             *
             * @return Returns an instance of IEntity or nullptr if not set.
             */
            virtual IEntity* getEntity() const = 0;

            /**
             * Adds this component to the given entity.
             *
             * @param[in] entity The entity to bind to.
             */
            virtual void setEntity(IEntity* entity) = 0;

            /**
             * Updates this component.
             *
             * @param[in] deltaTime The time in seconds since the last update.
             */
            virtual void update(float deltaTime) = 0;
        };
    }
}
