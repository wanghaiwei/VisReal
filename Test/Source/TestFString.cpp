/**
 * Created by rayfalling on 2020/11/2.
 * */

#include "TestFString.h"

#include "Logger/CoreLog.h"

using namespace Engine::Core;

void TestFString() {
	auto& logger = CoreLog::GetInstance();
	logger.SetLogLevel(LogLevel::Debug);

	logger.LogDebug(FString("Test FString function"));
	const auto start = std::chrono::system_clock::now();
	FString string(80);
	string.Append("Test string. ");
	logger.LogDebug(string);

	string.Append(FString("AppendString."));
	logger.LogDebug(string);

	const auto end = std::chrono::system_clock::now();
	const auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
	logger.LogDebug(FString::Format("FString multi thread test finished in: {0} microseconds", duration.count()));

}