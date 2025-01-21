using DataStructures

mutable struct UndoRedoManager
    undo_stack::Deque{String}
    redo_stack::Deque{String}
end

UndoRedoManager() = UndoRedoManager(Deque{String}(), Deque{String}())

function do_action(manager::UndoRedoManager, action::String)
    push!(manager.undo_stack, action)
    empty!(manager.redo_stack)  # Xóa redo stack khi có hành động mới
    println("Thực hiện hành động: ", action)
    println("  undo_stack: ", manager.undo_stack)
    println("  redo_stack: ", manager.redo_stack, "\n")
end

function undo(manager::UndoRedoManager)
    if isempty(manager.undo_stack)
        println("Không có hành động nào để hoàn tác.")
        println("  undo_stack: ", manager.undo_stack)
        println("  redo_stack: ", manager.redo_stack, "\n")
        return
    end

    action = pop!(manager.undo_stack)
    push!(manager.redo_stack, action)
    println("Hoàn tác hành động: ", action)
    println("  undo_stack: ", manager.undo_stack)
    println("  redo_stack: ", manager.redo_stack, "\n")
end

function redo(manager::UndoRedoManager)
    if isempty(manager.redo_stack)
        println("Không có hành động nào để làm lại.")
        println("  undo_stack: ", manager.undo_stack)
        println("  redo_stack: ", manager.redo_stack, "\n")
        return
    end

    action = pop!(manager.redo_stack)
    push!(manager.undo_stack, action)
    println("Làm lại hành động: ", action)
    println("  undo_stack: ", manager.undo_stack)
    println("  redo_stack: ", manager.redo_stack, "\n")
end

# Ví dụ sử dụng
manager = UndoRedoManager()

do_action(manager, "Gõ 'Hello'")  # Hành động 1
do_action(manager, "Gõ ' World'")  # Hành động 2
undo(manager)  # Hành động 3
undo(manager)  # Hành động 4
redo(manager)  # Hành động 5
redo(manager)
undo(manager)
do_action(manager, "Gõ '!'")
undo(manager)
undo(manager)
redo(manager)