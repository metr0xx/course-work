struct Handlers {
	static void AddStudentHandler();
	static void EditStudentHandler();
	static void DrawStudentsHandler(List<Student> students = FileInteraction::ReadData());
	static void DeleteStudentHandler();
	static void SortStudentsHandler();
};