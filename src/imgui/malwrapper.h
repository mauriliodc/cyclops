// ImGui GLFW binding with OpenGL
// https://github.com/ocornut/imgui

class CyclopsViewer;
bool        ImGui_ImplGlfw_Init(CyclopsViewer* viewer, bool install_callbacks);
void        ImGui_ImplGlfw_Shutdown();
void        ImGui_ImplGlfw_NewFrame();

// Use if you want to reset your rendering device without losing ImGui state.
void        ImGui_ImplGlfw_InvalidateDeviceObjects();
bool        ImGui_ImplGlfw_CreateDeviceObjects();

// GLFW callbacks (installed by default if you enable 'install_callbacks' during initialization)
// Provided here if you want to chain callbacks.
// You can also handle inputs yourself and use those as a reference.
void        ImGui_ImplGlfw_MouseButtonCallback(CyclopsViewer* window, int button, int action, int mods);
void        ImGui_ImplGlfw_ScrollCallback(CyclopsViewer* window, double xoffset, double yoffset);
void        ImGui_ImplGlFw_KeyCallback(CyclopsViewer* window, int key, int scancode, int action, int mods);
void        ImGui_ImplGlfw_CharCallback(CyclopsViewer* window, unsigned int c);
