/*
** EPITECH PROJECT, 2020
** old_logic.cpp
** File description:
** old_logic.cpp
*/


//LOAD GRAPHICAL API
void loadGraphicalAPI(const std::string &graphicalLibPath)
{
    if (isWindowlessSession)
        return;
    try
    {
        _graphicalApi = std::make_unique<GraphicalAPI>(graphicalLibPath);
        _graphicalApi->reloadAPI(graphicalLibPath);
        _display = _graphicalApi->createDisplay(_videoSettings, _projectName);
        GraphicalAPI::CurrentDisplay = _display;
        _splashScreen = std::make_unique<SplashScreen>(_projectPath);
        if (isDebugSession)
            _display->setLogLevel(0);
        else
            _display->setLogLevel(5);
    } catch (GraphicalException &e) {
        e.what();
        throw;
    } catch (std::exception &e) {
        Logger::log("[Graphical API] " + std::string(e.what()), Logger::MAJOR);
        throw;
    }
};



//LOAD SCRIPTING API
void loadScriptingAPI(std::unique_ptr<IScriptFactory> scriptFactory)
{
    _scriptingApi = std::make_unique<ScriptingApi>(std::move(scriptFactory));
}

void draw()
{
    if (!_game.isWindowLessSession())
    {
        GraphicalAPI::CurrentDisplay->beginDrawing();
        CameraComponent::Current->begin3dMode();
        for (auto &e: _entities)
            if (e->isActive() && !e->transform->parent() && !e->componentExist<CanvasComponent>())
                e->draw();
        CameraComponent::Current->end3dMode();
        for (auto &e: _entities)
        {
            auto canvas = e->getComponent<CanvasComponent>();
            if (e->isActive() && !e->transform->parent())
                e->draw2d(canvas);
        }
        GraphicalAPI::CurrentDisplay->endDrawing();
    }
}

void splashScreen()
{
    while (!isWindowlessSession && !_splashScreen->isFinished()) {
        _time.computeDeltaTime();
        _splashScreen->update();
    }
}


void Polymorph::Entity::draw()
{
    if (!_active || componentExist<CanvasComponent>())
        return;
    Drawable2d c = getComponent<ADrawable2dComponent>();

    if (!!c && c->enabled)
        c->draw();
    for (auto &c : **transform)
        c->gameObject->draw();
    Drawable3d c3 = getComponent<ADrawable3dComponent>();

    if (!!c3 && c3->enabled)
        c3->draw();
    for (auto &c3 : **transform)
        c3->gameObject->draw();
}
void Polymorph::Entity::draw2d(Canvas canvas)
{
    if (!_active)
        return;
    Drawable2d c = getComponent<ADrawable2dComponent>();
    Canvas tmp = getComponent<CanvasComponent>();

    if (!!c && c->enabled && !!canvas)
        c->draw(canvas);
    for (auto &c : **transform) {
        if (!canvas)
            c->gameObject->draw2d(tmp);
        else
            c->gameObject->draw2d(canvas);
    }
}