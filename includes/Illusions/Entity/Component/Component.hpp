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
         * The base class for a component.
         */
        class Component : public IComponent
        {
        public:
            /**
            * Initializes a new instance of this class.
            */
            Component();

            /**
             * Cleans up all the resources used by this class.
             */
            virtual ~Component();

            /**
             * Gets the entity to which this component belongs to.
             *
             * @return Returns an instance of IEntity or nullptr if not set.
             */
            virtual IEntity* getEntity() const;

            /**
             * Adds this component to the given entity.
             *
             * @param[in] entity The entity to bind to.
             */
            virtual void setEntity(IEntity* entity);

            /**
             * Updates this component.
             *
             * @param[in] deltaTime The time in seconds since the last update.
             */
            virtual void update(float deltaTime);

        private:
            /**
             * The current entity that this component is bound to.
             */
            IEntity* m_entity;
        };
    }
}
