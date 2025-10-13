package ui

import (
	"fmt"
	"os"
	"os/exec"
	"runtime"

	"github.com/charmbracelet/bubbles/list"
	"github.com/charmbracelet/bubbletea"
	"github.com/charmbracelet/lipgloss"
)

type menuModel struct {
	list list.Model
}

type MenuItem struct {
	Name  string
	Ring  string
	Color lipgloss.Color
	File  string
}

var MenuItems = []MenuItem{
	{Name: "Pain (Nagato)", Ring: "零", Color: 零, File: "pain"},
	{Name: "Deidara", Ring: "青", Color: 青, File: "deidara"},
	{Name: "Konan", Ring: "白", Color: 白, File: "konan"},
	{Name: "Itachi Uchiha", Ring: "朱", Color: 朱, File: "itachi"},
	{Name: "Zetsu", Ring: "亥", Color: 亥, File: "zetsu"},
	{Name: "Orochimaru", Ring: "空", Color: 空, File: "orochimaru"},
	{Name: "Jūzō Biwa", Ring: "南", Color: 南, File: "juzu"},
	{Name: "Kisame Hoshigaki", Ring: "南", Color: 南, File: "kisame"},
	{Name: "Kakuzu", Ring: "北", Color: 北, File: "kakuzo"},
	{Name: "Kakuzu's Partner", Ring: "三", Color: 三, File: "kakuzo_partner"},
	{Name: "Sasori", Ring: "玉", Color: 玉, File: "sasori"},
	{Name: "Tobi (Obito)", Ring: "玉", Color: 玉, File: "tobi"},
}

func MenuItemsToList() []list.Item {
	items := make([]list.Item, len(MenuItems))
	for i, menuItem := range MenuItems {
		items[i] = menuItem
	}
	return items
}

func (m MenuItem) FilterValue() string {
	return m.Name
}

func (m MenuItem) Title() string {
	return m.Name
}

func (m MenuItem) Description() string {
	return lipgloss.NewStyle().Foreground(m.Color).Render(m.Ring)
}

func (m menuModel) Init() tea.Cmd {
	return nil
}

func (m menuModel) Update(msg tea.Msg) (tea.Model, tea.Cmd) {
	switch msg := msg.(type) {
	case tea.KeyMsg:
		switch msg.String() {
		case "enter":
			if selectedItem, ok := m.list.SelectedItem().(MenuItem); ok {
				characterFilePath := fmt.Sprintf("./members/%s.json", selectedItem.File)
				character, err := LoadCharacter(characterFilePath)
				if err != nil {
					fmt.Println("Error loading character:", err)
					return m, nil
				}

				wiper()
				DisplayCharacter(character)

				wiper()
				return m, nil
			}
		case "q":
			return m, tea.Quit
		}
	}

	var cmd tea.Cmd
	m.list, cmd = m.list.Update(msg)
	return m, cmd
}

func (m menuModel) View() string {
	return m.list.View() + "\n" + FooterStyle.Render("\nenter: unveil | q: quit")
}

func Menu() {
	for {
		wiper()

		items := MenuItemsToList()
		delegate := list.NewDefaultDelegate()
		delegate.Styles.SelectedTitle = HighlightedStyle
		delegate.Styles.SelectedDesc = HighlightedStyle

		menuList := list.New(items, delegate, 50, len(items)+2)
		menuList.Title = "|- Unveil the hidden order -|"
		menuList.Styles.Title = HeaderStyle
		menuList.Styles.PaginationStyle = FooterStyle
		menuList.SetShowHelp(false)

		m := menuModel{list: menuList}

		if _, err := tea.NewProgram(m).Run(); err != nil {
			fmt.Println("Error running menu program:", err)
			os.Exit(1)
		}

		break
	}
}

func wiper() {
	var cmd *exec.Cmd
	if runtime.GOOS == "windows" {
		cmd = exec.Command("cmd", "/c", "cls")
	} else {
		cmd = exec.Command("clear")
	}

	cmd.Stdout = os.Stdout

	cmd.Run()
}
