# GameEventSystem

The design pattern I chose was a singleton to make sure that only one Game engine controls the game at any time, singletons make sure only one instance of something can exist at once.
Some advantages of using a singleton is that it reduces namespace pollution, it makes it easy to allow more than one instance, and allows extension by subclassing
some disadvantages are that implemntations can be less efficient than a global type, there are some concurrency pitfalls, can be misused in scenarios when multiple instances are preferable.
