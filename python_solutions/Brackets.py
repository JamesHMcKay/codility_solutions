class Stack:
    def __init__(self):
        self.values = [0] * 300000
        self.head = -1

    def push(self, value):
        self.head = self.head + 1
        self.values[self.head] = value

    def pop(self, value):
        if self.head == -1:
            return None;
        self.head = self.head - 1

        if value == "]" and self.values[self.head + 1] == "[":
            return True
        if value == ")" and self.values[self.head + 1] == "(":
            return True
        if value == "}" and self.values[self.head + 1] == "{":
            return True
        return False

    def get_size(self):
        return self.head


def solution(S):
    stack = Stack()

    for element in S:
        if element in ["(", "[", "{"]:
            stack.push(element)
        else:
            result = stack.pop(element)
            if result != True:
                return 0
    if stack.get_size() != -1:
        return 0

    return 1