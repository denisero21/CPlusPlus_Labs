object Form1: TForm1
  Left = 0
  Top = 0
  Caption = 'Form1'
  ClientHeight = 427
  ClientWidth = 770
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  OldCreateOrder = False
  PixelsPerInch = 96
  TextHeight = 13
  object Book: TStringGrid
    Left = 8
    Top = 8
    Width = 289
    Height = 186
    ColCount = 2
    DefaultColWidth = 130
    FixedCols = 0
    RowCount = 6
    Options = [goFixedVertLine, goFixedHorzLine, goVertLine, goHorzLine, goRangeSelect, goEditing]
    TabOrder = 0
    RowHeights = (
      24
      24
      24
      24
      24
      24)
  end
  object Add: TButton
    Left = 8
    Top = 200
    Width = 81
    Height = 25
    Caption = 'Add'
    TabOrder = 1
    OnClick = AddClick
  end
  object TreeView: TTreeView
    Left = 441
    Top = 8
    Width = 321
    Height = 153
    Indent = 19
    TabOrder = 2
  end
  object Create: TButton
    Left = 95
    Top = 200
    Width = 81
    Height = 25
    Caption = 'Create'
    TabOrder = 3
    OnClick = CreateClick
  end
  object Plus: TButton
    Left = 303
    Top = 169
    Width = 25
    Height = 25
    Caption = '+'
    TabOrder = 4
    OnClick = PlusClick
  end
  object Print: TButton
    Left = 182
    Top = 200
    Width = 81
    Height = 25
    Caption = 'Print'
    TabOrder = 5
    OnClick = PrintClick
  end
  object Board: TMemo
    Left = 441
    Top = 167
    Width = 321
    Height = 235
    ScrollBars = ssVertical
    TabOrder = 6
  end
  object Delete: TButton
    Left = 8
    Top = 258
    Width = 81
    Height = 25
    Caption = 'Delete'
    TabOrder = 7
    OnClick = DeleteClick
  end
  object DSEdit: TEdit
    Left = 8
    Top = 231
    Width = 105
    Height = 21
    TabOrder = 8
    TextHint = 'Enter key'
  end
  object Search: TButton
    Left = 95
    Top = 258
    Width = 75
    Height = 25
    Caption = 'Search'
    TabOrder = 9
    OnClick = SearchClick
  end
  object Task: TButton
    Left = 176
    Top = 258
    Width = 75
    Height = 25
    Caption = 'Task'
    TabOrder = 10
    OnClick = TaskClick
  end
end
