#include <stdio.h>

#include <math.h>
#include "Circuit.h"

static Circuit nand2_CircuitA(void) {

    char *title = "Circuit A: Two-Inputs NAND Gate";

    // Create the inputs
    int NINPUTS = 2;
    Boolean x = new_Boolean(false);
    Boolean y = new_Boolean(false);
    Boolean* inputs = new_Boolean_array(NINPUTS);
    inputs[0] = x;
    inputs[1] = y;

    // Create the outputs
    int NOUTPUTS = 1;
    Boolean result = new_Boolean(false);
    Boolean* outputs = new_Boolean_array(NOUTPUTS);
    outputs[0] = result;

    // Create the NAND Gate
    int NGATES = 1;
    Gate A1 = new_Nand2Gate();
    Gate* gates = new_Gate_array(NGATES);
    gates[0] = A1;

    // Create the Circuit
    Circuit circuit = new_Circuit(title, NINPUTS, inputs, NOUTPUTS, outputs, NGATES, gates);

    // Connect the Gates in the circuit
    Circuit_connect(circuit, x, Gate_getInput(A1, 0));
    Circuit_connect(circuit, y, Gate_getInput(A1, 1));

    Boolean xNANDy = Gate_getOutput(A1);

    Circuit_connect(circuit, xNANDy, result);

    return circuit;

}

static Circuit extra_credit(void) {
    char *title = "Extra Credit Circuit: G = not c";

    // Create the inputs
    int NINPUTS = 3;
    Boolean a = new_Boolean(false);
    Boolean b = new_Boolean(false);
    Boolean c = new_Boolean(false);
    Boolean* inputs = new_Boolean_array(NINPUTS);
    inputs[0] = a;
    inputs[1] = b;
    inputs[2] = c;

    //create the outputs
    int NOUTPUTS = 2;
    Boolean r1 = new_Boolean(false);
    Boolean r2 = new_Boolean(false);
    Boolean* outputs = new_Boolean_array(NOUTPUTS);
    outputs[0] = r1;
    outputs[1] = r2;

    //create the gates
    int NGATES = 4;
    Gate I1 = new_Inverter();
    Gate O1 = new_OrGate();
    Gate I2 = new_Inverter();
    Gate A1 = new_AndGate();
    Gate* gates = new_Gate_array(NGATES);
    gates[0] = I1;
    gates[1] = O1;
    gates[2] = I2;
    gates[3] = A1;

    //create the circuit
    Circuit circuit = new_Circuit(title, NINPUTS, inputs, NOUTPUTS, outputs, NGATES, gates);

    //connect the gates in the circuit
    //a or not a
    Circuit_connect(circuit, a, Gate_getInput(O1, 0));
    Circuit_connect(circuit, a, Gate_getInput(I1, 0));
    Circuit_connect(circuit, Gate_getOutput(I1), Gate_getInput(O1, 1));
    //(a or not a) and b)
    Circuit_connect(circuit, Gate_getOutput(O1), Gate_getInput(A1, 0));
    Circuit_connect(circuit, b, Gate_getInput(A1, 1));
    //not c
    Circuit_connect(circuit, c, Gate_getInput(I2, 0));

    Boolean aORNOTaANDb = Gate_getOutput(A1);
    Boolean NOTc = Gate_getOutput(I2);

    Circuit_connect(circuit, aORNOTaANDb, outputs[0]);
    Circuit_connect(circuit, NOTc, outputs[1]);

    return circuit;
}

/*
static void testNand2_CircuitA(void) {

    Circuit circuit = nand2_CircuitA();
    printf("------------------------------------------------------Testing %s------------------------------------------------------\n", Circuit_getTitle(circuit));
    for (int i = 0; i < 4; i++) {
        bool in0 = (i & 2) != 0;
        bool in1 = (i & 1) != 0;
        Circuit_setInput(circuit, 0, in0);
        Circuit_setInput(circuit, 1, in1);
        Circuit_update(circuit);
        printf("%s %s -> %s\n",
               Boolean_toString(Circuit_getInput(circuit, 0)),
               Boolean_toString(Circuit_getInput(circuit, 1)),
               Boolean_toString(Circuit_getOutput(circuit, 0)));
    }

    free_Circuit(circuit);
}
*/

static Circuit and2_CircuitB(void) {

    char *title = "Circuit B: Two-Inputs AND Gate";

    // Create the inputs
    int NINPUTS = 2;
    Boolean x = new_Boolean(false);
    Boolean y = new_Boolean(false);
    Boolean* inputs = new_Boolean_array(NINPUTS);
    inputs[0] = x;
    inputs[1] = y;

    // Create the outputs
    int NOUTPUTS = 1;
    Boolean result = new_Boolean(false);
    Boolean* outputs = new_Boolean_array(NOUTPUTS);
    outputs[0] = result;

    // Create the AND Gate
    int NGATES = 1;
    Gate A1 = new_AndGate();
    Gate* gates = new_Gate_array(NGATES);
    gates[0] = A1;

    // Create the Circuit
    Circuit circuit = new_Circuit(title, NINPUTS, inputs, NOUTPUTS, outputs, NGATES, gates);

    // Connect the Gates in the circuit
    Circuit_connect(circuit, x, Gate_getInput(A1, 0));
    Circuit_connect(circuit, y, Gate_getInput(A1, 1));

    Boolean xANDy = Gate_getOutput(A1);

    Circuit_connect(circuit, xANDy, result);

    return circuit;
}
/*
static void testAnd2_CircuitB(void) {

    Circuit circuit = and2_CircuitB();
    printf("------------------------------------------------------Testing %s-------------------------------------------------------\n", Circuit_getTitle(circuit));
    for (int i = 0; i < 4; i++) {
        bool in0 = (i & 2) != 0;
        bool in1 = (i & 1) != 0;
        Circuit_setInput(circuit, 0, in0);
        Circuit_setInput(circuit, 1, in1);
        Circuit_update(circuit);
        printf("%s %s -> %s\n",
               Boolean_toString(Circuit_getInput(circuit, 0)),
               Boolean_toString(Circuit_getInput(circuit, 1)),
               Boolean_toString(Circuit_getOutput(circuit, 0)));
    }

    free_Circuit(circuit);
}
*/

// ( x AND y ) or [ ( x or y ) AND ! z ]
static Circuit and2_or2_CircuitC(void) {

    char *title = "Circuit C: Three-Inputs, Two AND Gates, Two OR Gates, One Inverter";

    // Create the inputs
    int NINPUTS = 3;
    Boolean x = new_Boolean(false);
    Boolean y = new_Boolean(false);
    Boolean z = new_Boolean(false);
    Boolean* inputs = new_Boolean_array(NINPUTS);
    inputs[0] = x;
    inputs[1] = y;
    inputs[2] = z;

    // Create the outputs
    int NOUTPUTS = 1;
    Boolean result = new_Boolean(false);
    Boolean* outputs = new_Boolean_array(NOUTPUTS);
    outputs[0] = result;

    // Create the Gates
    int NGATES = 5;
    Gate A1 = new_AndGate();
    Gate O1 = new_OrGate();
    Gate I1 = new_Inverter();
    Gate A2 = new_AndGate();
    Gate O3 = new_OrGate();
    Gate* gates = new_Gate_array(NGATES);
    gates[0] = A1;
    gates[1] = O1;
    gates[2] = I1;
    gates[3] = A2;
    gates[4] = O3;

    // Create the Circuit

    Circuit circuit = new_Circuit(title, NINPUTS, inputs, NOUTPUTS, outputs, NGATES, gates);

    // Connect the Gates in the circuit
    Circuit_connect(circuit, x, Gate_getInput(A1, 0));
    Circuit_connect(circuit, y, Gate_getInput(A1, 1));
    Boolean xA1y = Gate_getOutput(A1);

    Circuit_connect(circuit, x, Gate_getInput(O1, 0));
    Circuit_connect(circuit, y, Gate_getInput(O1, 1));
    Boolean xO1y = Gate_getOutput(O1);

    Circuit_connect(circuit, z, Gate_getInput(I1, 0));
    Boolean zI1 = Gate_getOutput(I1);

    Circuit_connect(circuit, xO1y, Gate_getInput(A2, 0));
    Circuit_connect(circuit, zI1, Gate_getInput(A2, 1));
    Boolean xO1yA2zI1 = Gate_getOutput(A2);

    Circuit_connect(circuit, xA1y, Gate_getInput(O3, 0));
    Circuit_connect(circuit, xO1yA2zI1, Gate_getInput(O3, 1));
    Boolean final = Gate_getOutput(O3);

    Circuit_connect(circuit, final, result);

    return circuit;
}
/*static void testAnd2_or2_CircuitC(void) {

    Circuit circuit = and2_or2_CircuitC();
    printf("------------------------------------------------------Testing %s--------------------\n", Circuit_getTitle(circuit));
    for (int i = 0; i < 8; i++) {
        bool in0 = (i & 4) != 0;
        bool in1 = (i & 2) != 0;
        bool in2 = (i & 1) != 0;
        Circuit_setInput(circuit, 0, in0);
        Circuit_setInput(circuit, 1, in1);
        Circuit_setInput(circuit, 2, in2);
        Circuit_update(circuit);
        printf("%s %s %s -> %s\n",
               Boolean_toString(Circuit_getInput(circuit, 0)),
               Boolean_toString(Circuit_getInput(circuit, 1)),
               Boolean_toString(Circuit_getInput(circuit, 2)),
               Boolean_toString(Circuit_getOutput(circuit, 0)));
    }

    free_Circuit(circuit);
}*/

// Test Function that tests any circuit that is passed to it
static void testAny(Circuit circuit) {
    printf("\n----------------Testing %s\n\n", Circuit_getTitle(circuit));
    int NINPUTS = Circuit_numInputs(circuit);
    int NOUTPUTS = Circuit_numOutputs(circuit);

    for (int i = 0; i < pow(2, NINPUTS); i++) {
        for (int j = 0; j < NINPUTS; j++) {
            bool in = (i & (1 << j)) != 0;
            Circuit_setInput(circuit, j, in);
        }
        Circuit_update(circuit);
        printf("Inputs: ");
        for (int j = 0; j < NINPUTS; j++) {
            printf("%s ", Boolean_toString(Circuit_getInput(circuit, j)));
        }
        printf("\nOutputs: ");
        for (int j = 0; j < NOUTPUTS; j++) {
            printf("%s ", Boolean_toString(Circuit_getOutput(circuit, j)));
        }
        printf("\n\n");
    }

    printf("\n");

    free_Circuit(circuit);

}






int main(int argc, char **argv) {

    testAny(nand2_CircuitA());
    testAny(and2_CircuitB());
    testAny(and2_or2_CircuitC());
    testAny(extra_credit());

    return 0;
}
