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
        /**
         * The ISubsystem interface describes a subsystem.
         */
        class ISubsystem
        {
        public:
            /**
             * Cleans up all the resources used by this class.
             */
            virtual ~ISubsystem() { }

            /**
             * Updates the subsystem.
             */
            virtual void update() = 0;
        };
    }
}
