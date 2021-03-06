#pragma once

struct lcInstructionsPageSetup
{
	float Width;
	float Height;
	float MarginLeft;
	float MarginRight;
	float MarginTop;
	float MarginBottom;
};

enum class lcInstructionsDirection
{
	Horizontal,
	Vertical
};

struct lcInstructionsPageSettings
{
	int Rows;
	int Columns;
	lcInstructionsDirection Direction;
};

struct lcInstructionsStep
{
	QRectF Rect;
	lcModel* Model;
	lcStep Step;
};

struct lcInstructionsPage
{
//	lcInstructionsPageSettings Settings;
	std::vector<lcInstructionsStep> Steps;
};

class lcInstructions
{
public:
	lcInstructions(Project* Project = nullptr);

	void SetDefaultPageSettings(const lcInstructionsPageSettings& PageSettings);

	std::vector<lcInstructionsPage> mPages;
	lcInstructionsPageSettings mPageSettings;
	lcInstructionsPageSetup mPageSetup;

protected:
	void CreatePages();
	void AddDefaultPages(lcModel* Model, std::vector<const lcModel*>& AddedModels);

	Project* mProject = nullptr;

	static const float mDisplayDPI;
};
