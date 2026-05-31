import SwiftUI
#if os(macOS)
import AppKit

final class CalcAppDelegate: NSObject, NSApplicationDelegate {
    func applicationShouldTerminateAfterLastWindowClosed(_ sender: NSApplication) -> Bool {
        return true
    }
}
#endif

@main
struct CalcApp: App {
#if os(macOS)
    @NSApplicationDelegateAdaptor(CalcAppDelegate.self) var appDelegate
#endif

    var body: some Scene {
        WindowGroup {
            CalcView()
        }
    }
}
