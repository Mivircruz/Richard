#pragma once

#ifndef APPLICATION_H
#define APPLICATION_H

namespace Richard {
    class Application {
        public:
            /*Methods*/
            Application() {}
            ~Application() {}

            virtual void Initialize() {}
            virtual void Shutdown() {}

            virtual void Update() {}
            virtual void Render() {}
    };
}

#endif