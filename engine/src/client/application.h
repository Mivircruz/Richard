#pragma once

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