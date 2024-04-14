#include <iostream>
#include <windows.h>

void clickMouse(int clickCount, int interval) {
    INPUT input[2];  // Create an array of INPUT to store both down and up mouse events
    // Set up the down event
    input[0].type = INPUT_MOUSE;
    input[0].mi.mouseData = 0;
    input[0].mi.dx = 0;
    input[0].mi.dy = 0;
    input[0].mi.dwFlags = MOUSEEVENTF_LEFTDOWN;
    input[0].mi.time = 0;
    input[0].mi.dwExtraInfo = NULL;

    // Set up the up event
    input[1].type = INPUT_MOUSE;
    input[1].mi.mouseData = 0;
    input[1].mi.dx = 0;
    input[1].mi.dy = 0;
    input[1].mi.dwFlags = MOUSEEVENTF_LEFTUP;
    input[1].mi.time = 0;
    input[1].mi.dwExtraInfo = NULL;
    int percentComplete = 0;

    int progressInterval = clickCount / 100;  // Update progress every 1% of the total clicks

    for (int i = 0; i < clickCount; ++i) {
        SendInput(2, input, sizeof(INPUT));  // Send the down and up event
        Sleep(interval);  // Sleep for the specified interval between clicks

        // Print progress for every 1% completed
         percentComplete = (i * 100) / clickCount;
         std::cout << percentComplete << "% (" << i << "/" << clickCount << ") clicks completed.\r";
         std::flush(std::cout);  // Ensure the output is displayed immediately
         
        
    }
    std::cout << std::endl;  // Move to the next line after completing the loop
}

int main() {
    int totalClicks = 1000000;
    int duration = 1800; // Duration in seconds for the clicks to be completed
    int interval = duration * 1000 / totalClicks; // Calculate interval in milliseconds
    std::cout << "Enter the number of clicks: ";
    std::cin >> totalClicks;
    // Provide some delay before starting the auto-clicker
    std::cout << "Starting in 5 seconds..." << std::endl;
    Sleep(5000);

    DWORD startTime = GetTickCount(); // Record start time
    clickMouse(totalClicks, interval);
    DWORD endTime = GetTickCount(); // Record end time

    std::cout << "Completed " << totalClicks << " clicks in " << (endTime - startTime) / 1000.0 << " seconds." << std::endl;

    return 0;
}
