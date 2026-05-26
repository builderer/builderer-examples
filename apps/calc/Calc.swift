import SwiftUI
import AppKit

final class CalcAppDelegate: NSObject, NSApplicationDelegate {
    func applicationShouldTerminateAfterLastWindowClosed(_ sender: NSApplication) -> Bool {
        return true
    }
}

@main
struct CalcApp: App {
    @NSApplicationDelegateAdaptor(CalcAppDelegate.self) var appDelegate

    var body: some Scene {
        WindowGroup {
            CalcView()
        }
    }
}
