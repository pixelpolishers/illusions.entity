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
         * A basic representation of a subsystem.
         */
        class Subsystem: public ISubsystem
        {
        public:
            /**
             * Initializes a new instance of this class.
             */
            Subsystem();

            /**
             * Cleans up all the resources used by this class.
             */
            virtual ~Subsystem();

            /**
             * Updates the subsystem.
             */
            virtual void update();
        };
    }
}
