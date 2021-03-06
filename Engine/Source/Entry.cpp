/**
 * Created by rayfalling on 2020/10/18.
 * */

#include "Marco/Constant.h"
#include "Entry.h"

#include "RenderThread.h"
#include "EventLoop.h"

bool Engine::InitEngine() {
	atexit(Terminate);

	/* Init Engine Logger */
	Logger = Core::CoreLog::GetInstancePtr();
	Logger->LogInfo(Core::C_ENGINE_START);

	/* Start Render Thread */
	InitRenderThread();

	/* Main Event Loop */
	MessageLoop = Event::EventLoop::GetInstancePtr();
	MessageLoop->Run();

	return true;
}

void Engine::TerminateEventLoop() {
	MessageLoop->Stop();
}

void Engine::Terminate() {
	TerminateEventLoop();
	TerminateRenderThread();
	Core::CoreLog::GetInstance().LogInfo(Core::C_ENGINE_STOP);
	Logger->FlushAll();
}
