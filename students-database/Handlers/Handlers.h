struct Handlers {
	static void AddStudentHandler();
	static void EditStudentHandler();
	static void DrawStudentsHandler(vector<Student> students = FileInteraction::ReadData());
	static void DeleteStudentHandler();
	static void SortStudentsHandler();
};