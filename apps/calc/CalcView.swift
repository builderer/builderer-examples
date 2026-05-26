import SwiftUI
import CalcBridge

struct CalcView: View {
    @State private var input: String = "2+3"
    @State private var result: String = ""

    var body: some View {
        VStack(spacing: 16) {
            Text("Calc — Swift + C++ interop")
                .font(.title)
            TextField("Enter expression (e.g. 2+3)", text: $input)
                .textFieldStyle(.roundedBorder)
            Button("Evaluate") {
                let value = input.withCString { calc_evaluate($0) }
                result = value.isNaN ? "?" : String(value)
            }
            Text("= \(result)")
                .font(.title2)
        }
        .padding(40)
        .frame(minWidth: 360, minHeight: 200)
    }
}
