package ui

import (
	"github.com/charmbracelet/lipgloss"
	"strings"
)

var (
	零   = lipgloss.Color("#743774") // Pain
	青   = lipgloss.Color("#1B9AC9") // Deidara
	白   = lipgloss.Color("#CCCCCC") // Konan
	朱   = lipgloss.Color("#DC143C") // Itachi Uchiha
	亥   = lipgloss.Color("#B13A2A") // Zetsu
	空   = lipgloss.Color("#5B7C99") // Orochimaru
	南   = lipgloss.Color("#CBA632") // Jūzō Biwa & Kisame Hoshigaki
	北   = lipgloss.Color("#053805") // Kakuzu
	三   = lipgloss.Color("#FFA500") // Kakuzu's fourth partner & Hidan
	玉   = lipgloss.Color("#674EA7") // Sasori & Tobi
	AR  = lipgloss.Color("#E31012") // Akatsuki Red
	ADR = lipgloss.Color("#902020") // Akatsuki Dark Red
	AB  = lipgloss.Color("#040404") // Akatsuki Black
	AW  = lipgloss.Color("#E5E5E5") // Akatsuki White
	AG  = lipgloss.Color("#646968") // Akatsuki Gray
	AP  = lipgloss.Color("#C90076") // Akatsuki Pink
	AO  = lipgloss.Color("#FFA500") // Akatsuki Orange

	// Header Styles
	HeaderStyle = lipgloss.NewStyle().
			Bold(true).
			Italic(true).
			Foreground(AR)

	SubHeaderStyle = lipgloss.NewStyle().
			Italic(true).
			Foreground(AG)

	MemberHeaderStyle = lipgloss.NewStyle().
				Foreground(AR).
				Bold(true).
				Italic(true).
				Underline(true)

	BodyStyle = lipgloss.NewStyle().
			Margin(1, 2).
			Foreground(AW)

	MemberBodyStyle = lipgloss.NewStyle().
			Italic(false).
			Bold(true).
			Foreground(AW).
			MarginBottom(1).
			MarginTop(2)

	SectionHeaderStyle = lipgloss.NewStyle().
				Foreground(AR).
				Background(AB).
				MarginTop(1).
				Bold(true)

	HighlightedStyle = lipgloss.NewStyle().
				Foreground(AW).
				Background(AB).
				Padding(0, 1)

	FooterStyle = lipgloss.NewStyle().
			Foreground(AW)

	MemberFooterStyle = lipgloss.NewStyle().
				Bold(true).
				Italic(true).
				Foreground(AR).
				MarginTop(1)

	TableHeaderStyle = lipgloss.NewStyle().
				Foreground(AO).
				Italic(true)

	RankHeaderStyle = lipgloss.NewStyle().
			Foreground(AP).
			Bold(true)

	GeneralHeaderStyle = lipgloss.NewStyle().
				Foreground(AR).
				Background(AB).
				MarginTop(1).
				Bold(true)

	StatsRowStyle = lipgloss.NewStyle().
			Width(25).
			PaddingLeft(2).
			Align(lipgloss.Left)

	// Stat Styles
	normalStatStyle = lipgloss.NewStyle().
			Width(21).
			Foreground(AW).
			Background(AB).
			Bold(true).
			Align(lipgloss.Center).
		//Border(lipgloss.ThickBorder()).
		//BorderForeground(AB).
		Padding(1, 1)

	totalStatStyle = lipgloss.NewStyle().
			Width(21).
			Foreground(AB).
			Background(ADR).
			Bold(true).
			Align(lipgloss.Center).
		//Border(lipgloss.ThickBorder()).
		//BorderForeground(AB).
		Padding(1, 1)

	quoteTextStyle = lipgloss.NewStyle().
			Foreground(AW).
			Italic(true)

	quoteContextStyle = lipgloss.NewStyle().
				Foreground(AG)

	notAvailableStyle = lipgloss.NewStyle().
				Foreground(AG).
				Bold(true)
)

func generateDivider(header string, width int, glyph string) string {
	headerWidth := lipgloss.Width(header)
	fillerWidth := max(0, width-headerWidth)
	filler := strings.Repeat(glyph, fillerWidth/len(glyph))
	return lipgloss.JoinHorizontal(lipgloss.Center, header, filler)
}

func max(a, b int) int {
	if a > b {
		return a
	}
	return b
}
