package ui

import (
	"encoding/json"
	"fmt"
	"io/ioutil"
	"os"
	"strings"

	"github.com/charmbracelet/bubbles/viewport"
	tea "github.com/charmbracelet/bubbletea"
	"github.com/charmbracelet/lipgloss"
)

type Character struct {
	Name          string     `json:"name"`
	Alias         string     `json:"alias"`
	Ring          Ring       `json:"ring"`
	Appearance    Appearance `json:"appearance"`
	Background    string     `json:"background"`
	Abilities     []Ability  `json:"abilities"`
	Stats         Stats      `json:"stats"`
	Relationships []Relation `json:"relationships"`
	Quotes        Quotes     `json:"quotes"`
}

type Ring struct {
	Kanji   string `json:"kanji"`
	Meaning string `json:"meaning"`
	Color   string `json:"color"`
}

type Appearance struct {
	Height  string `json:"height"`
	Age     string `json:"age"`
	Clan    string `json:"clan"`
	Village string `json:"village"`
}

type Ability struct {
	Name        string  `json:"name"`
	Description string  `json:"description"`
	Rank        string  `json:"rank"`
	Rating      float64 `json:"rating"`
}

type Relation struct {
	Name    string `json:"name"`
	Dynamic string `json:"dynamic"`
}

type Quotes struct {
	NotAvailable bool
	List         []Quote
}

func (q *Quotes) UnmarshalJSON(data []byte) error {
	if string(data) == `"Not Available"` {
		q.NotAvailable = true
		return nil
	}

	var quotes []Quote
	if err := json.Unmarshal(data, &quotes); err != nil {
		return fmt.Errorf("invalid quotes format: %s", string(data))
	}
	q.NotAvailable = false
	q.List = quotes
	return nil
}

type Quote struct {
	Text    string `json:"text"`
	Context string `json:"context"`
}

type Stats struct {
	Ninjutsu     interface{} `json:"ninjutsu"`
	Taijutsu     interface{} `json:"taijutsu"`
	Genjutsu     interface{} `json:"genjutsu"`
	Intelligence interface{} `json:"intelligence"`
	Strength     interface{} `json:"strength"`
	Speed        interface{} `json:"speed"`
	Stamina      interface{} `json:"stamina"`
	HandSeals    interface{} `json:"handSeals"`
	Total        interface{} `json:"total"`
}

func (s *Stats) UnmarshalJSON(data []byte) error {
	if string(data) == `"Unknown"` || string(data) == `"Not Available"` {
		*s = Stats{}
		return nil
	}

	type Alias Stats
	var stats Alias
	if err := json.Unmarshal(data, &stats); err != nil {
		return fmt.Errorf("invalid stats format: %s", string(data))
	}

	*s = Stats(stats)
	return nil
}

func LoadCharacter(filePath string) (*Character, error) {
	file, err := ioutil.ReadFile(filePath)
	if err != nil {
		return nil, err
	}

	var character Character
	err = json.Unmarshal(file, &character)
	if err != nil {
		return nil, err
	}

	return &character, nil
}

func GenerateStyledContent(character *Character) string {
	var sb strings.Builder

	// Header
	sb.WriteString(MemberHeaderStyle.Render(fmt.Sprintf("%s (%s)\n", character.Name, character.Alias)))

	// Ring and Appearance
	sb.WriteString(fmt.Sprintf(
		"\n%s     %s %s\n%s   %s\n%s      %s\n%s     %s\n%s  %s\n\n",
		GeneralHeaderStyle.Render("  Ring  "),
		lipgloss.NewStyle().Foreground(lipgloss.Color(character.Ring.Color)).Render(character.Ring.Kanji),
		lipgloss.NewStyle().Foreground(AW).Render(character.Ring.Meaning),
		GeneralHeaderStyle.Render("  Height  "),
		lipgloss.NewStyle().Foreground(AW).Render(character.Appearance.Height),
		GeneralHeaderStyle.Render("  Age  "),
		lipgloss.NewStyle().Foreground(AW).Render(character.Appearance.Age),
		GeneralHeaderStyle.Render("  Clan  "),
		lipgloss.NewStyle().Foreground(AW).Render(character.Appearance.Clan),
		GeneralHeaderStyle.Render("  Village  "),
		lipgloss.NewStyle().Foreground(AW).Render(character.Appearance.Village),
	))

	// Background
	sb.WriteString(SectionHeaderStyle.Render("   Background                                  "))
	sb.WriteString(MemberBodyStyle.Render(fmt.Sprintf("\n%s\n", character.Background)))

	// Abilities
	sb.WriteString(SectionHeaderStyle.Render("   Abilities                                   "))
	for _, ability := range character.Abilities {
		rank := RankHeaderStyle.Render(fmt.Sprintf("(%s)", ability.Rank))
		rating := TableHeaderStyle.Render(fmt.Sprintf("   [Rating: %.1f]", ability.Rating))

		sb.WriteString(fmt.Sprintf(
			"\n\n\n󱍿  %s %s ⏽ %s\n\n%s\n",
			lipgloss.NewStyle().Bold(true).Foreground(AW).Render(ability.Name),
			rank,
			lipgloss.NewStyle().Foreground(AW).Render(ability.Description),
			rating,
		))
	}

	sb.WriteString("\n")

	// Stats Table
	sb.WriteString(SectionHeaderStyle.Render("   Stats                                     "))

	if isEmptyStats(character.Stats) {
		sb.WriteString(notAvailableStyle.Render("\n\n\n Not Available\n\n"))
	} else {

		statsTable := "\n\n\n" + lipgloss.JoinHorizontal(
			lipgloss.Top,
			normalStatStyle.Render(" Ninjutsu: "+fmt.Sprint(character.Stats.Ninjutsu)),
			normalStatStyle.Render("Taijutsu: "+fmt.Sprint(character.Stats.Taijutsu)),
			normalStatStyle.Render("Genjutsu: "+fmt.Sprint(character.Stats.Genjutsu)),
		)
		statsTable += "\n" + lipgloss.JoinHorizontal(
			lipgloss.Top,
			normalStatStyle.Render(" Intelligence: "+fmt.Sprint(character.Stats.Intelligence)),
			normalStatStyle.Render("Strength: "+fmt.Sprint(character.Stats.Strength)),
			normalStatStyle.Render("Speed: "+fmt.Sprint(character.Stats.Speed)),
		)
		statsTable += "\n" + lipgloss.JoinHorizontal(
			lipgloss.Top,
			normalStatStyle.Render(" Stamina: "+fmt.Sprint(character.Stats.Stamina)),
			normalStatStyle.Render("Hand Seals: "+fmt.Sprint(character.Stats.HandSeals)),
			totalStatStyle.Render("Total: "+fmt.Sprint(character.Stats.Total)),
		)

		sb.WriteString(statsTable + "\n\n")
	}

	// Relationships
	sb.WriteString(SectionHeaderStyle.Render("   Relationships                                 "))
	if len(character.Relationships) == 0 {
		sb.WriteString(lipgloss.NewStyle().Foreground(AW).Render("\n  None\n\n"))
	} else {
		nameStyle := lipgloss.NewStyle().
			Foreground(AR).
			//Background(AR).
			Bold(true)

		dynamicStyle := lipgloss.NewStyle().
			Foreground(AW)

		iconStyle := lipgloss.NewStyle().
			Foreground(AR).
			Background(AB)

		for _, relation := range character.Relationships {
			sb.WriteString(fmt.Sprintf(
				"\n\n\n%s %s%s %s",
				iconStyle.Render(" "),
				nameStyle.Render(relation.Name),
				nameStyle.Render(":"),
				dynamicStyle.Render(relation.Dynamic),
			))
		}
		sb.WriteString("\n\n")
	}

	// Quotes
	sb.WriteString(SectionHeaderStyle.Render("   Quotes                                     "))
	if character.Quotes.NotAvailable {
		sb.WriteString(notAvailableStyle.Render("  Not available.\n\n"))
	} else {
		for _, quote := range character.Quotes.List {
			sb.WriteString(fmt.Sprintf(
				"\n\n\n%s\n\n%s\n",
				quoteTextStyle.Render(fmt.Sprintf("\"%s\"", quote.Text)),
				quoteContextStyle.Render(fmt.Sprintf("    %s", quote.Context)),
			))
		}
	}

	return sb.String()
}

func isEmptyStats(stats Stats) bool {
	return stats.Ninjutsu == nil &&
		stats.Taijutsu == nil &&
		stats.Genjutsu == nil &&
		stats.Intelligence == nil &&
		stats.Strength == nil &&
		stats.Speed == nil &&
		stats.Stamina == nil &&
		stats.HandSeals == nil &&
		stats.Total == nil
}

// PagerModel handles the viewport for displaying character details
type PagerModel struct {
	viewport viewport.Model
	content  string
	ready    bool
}

func (m PagerModel) Init() tea.Cmd {
	return nil
}

// Update handles key events and window resizing
func (m PagerModel) Update(msg tea.Msg) (tea.Model, tea.Cmd) {
	switch msg := msg.(type) {
	case tea.KeyMsg:
		switch msg.String() {
		case "b":
			wiper()
			m.viewport.GotoTop()
			return m, tea.Quit
		case "q":
			wiper()
			os.Exit(0)
		}

	case tea.WindowSizeMsg:
		footerHeight := lipgloss.Height(m.footerView())
		if !m.ready {
			m.viewport = viewport.New(msg.Width, msg.Height-footerHeight)
			m.viewport.SetContent(m.content)
			m.ready = true
		} else {
			m.viewport.Width = msg.Width
			m.viewport.Height = msg.Height - footerHeight
		}
	}

	var cmd tea.Cmd
	m.viewport, cmd = m.viewport.Update(msg)
	return m, cmd
}

func (m PagerModel) View() string {
	if !m.ready {
		return "\n  Initializing..."
	}
	return fmt.Sprintf("%s\n%s", m.viewport.View(), m.footerView())
}

func (m PagerModel) footerView() string {
	return MemberFooterStyle.Render(fmt.Sprintf("%3.f%%", m.viewport.ScrollPercent()*100))
}

// DisplayCharacter starts the program to display a character's details
func DisplayCharacter(character *Character) {
	content := GenerateStyledContent(character)

	m := PagerModel{
		content: content,
	}

	p := tea.NewProgram(m, tea.WithAltScreen())
	if err := p.Start(); err != nil {
		fmt.Println("Error displaying character:", err)
	}
}
