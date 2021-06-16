/*
 * Copyright (C) 2020 Adrian Carpenter
 *
 * This file is part of Pingnoo (https://github.com/nedrysoft/pingnoo)
 *
 * An open-source cross-platform traceroute analyser.
 *
 * Created by Adrian Carpenter on 30/05/2021.
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef NEDRYSOFT_SYSTEMTRAY_SYSTEMTRAYCOMPONENT_H
#define NEDRYSOFT_SYSTEMTRAY_SYSTEMTRAYCOMPONENT_H

#include "SystemTraySpec.h"

#include <IComponent>

/**
 * @brief       The SystemTrayComponent provides an implemention of a system tray icon that displays information
 *              quickly and concisely to the user.
 */
class NEDRYSOFT_SYSTEMTRAY_DLLSPEC SystemTrayComponent :
        public QObject,
        public Nedrysoft::ComponentSystem::IComponent {

    private:
        Q_OBJECT

        Q_PLUGIN_METADATA(IID NedrysoftComponentInterfaceIID FILE "metadata.json")

        Q_INTERFACES(Nedrysoft::ComponentSystem::IComponent)

    public:
        /**
         * @brief       Constructs the SystemTrayComponent.
         */
        SystemTrayComponent();

        /**
         * @brief       Destroys the SystemTrayComponent.
         */
        ~SystemTrayComponent();

    public:
        /**
         * @brief       The initialiseEvent is called by the component loader to initialise the component.
         *
         * @details     Called by the component loader after all components have been loaded, called in load order.
         *
         * @see         Nedrysoft::ComponentSystem::IComponent::initialiseEvent
         */
        auto initialiseEvent() -> void override;

        /**
         *  @brief       The finaliseEvent is called by the component loader to de-initialise the component.
         *
         *  @details    Called by the component loader in reverse load order to shutdown the component.
         *
         *  @see         Nedrysoft::ComponentSystem::IComponent::finaliseEvent
         */
        auto finaliseEvent() -> void override;

    private:
        //! @cond

        //! @endcond
};

#endif // NEDRYSOFT_SYSTEMTRAY_SYSTEMTRAYCOMPONENT_H