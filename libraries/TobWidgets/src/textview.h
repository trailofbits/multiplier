#pragma once

#include "glyphcache.h"
#include "textmodel.h"

#include <QFontMetricsF>
#include <QFrame>
#include <QRectF>

#include <memory>
#include <optional>

namespace drgui {

struct TextViewTheme final {
  QColor background;
  QColor foreground;
  std::unordered_map<TokenColorID, QColor> color_map;
};

class TextView final : public QFrame {
  Q_OBJECT

public:
  TextView(TextModel &model, QWidget *parent = nullptr);
  virtual ~TextView();

  void setTheme(const TextViewTheme &theme);
  std::optional<QString> getSelection();

  TextView(const TextView &) = delete;
  TextView &operator=(const TextView &) = delete;

protected:
  virtual void resizeEvent(QResizeEvent *event) override;
  virtual void paintEvent(QPaintEvent *event) override;
  virtual void mousePressEvent(QMouseEvent *event) override;
  virtual void mouseReleaseEvent(QMouseEvent *event) override;
  virtual void mouseMoveEvent(QMouseEvent *event) override;
  virtual void focusOutEvent(QFocusEvent *event) override;

private:
  struct PrivateData;
  std::unique_ptr<PrivateData> d;

private slots:
  void onModelReset();

public:
  struct TokenEntity final {
    QRectF bounding_box;
    TokenID token_id;
  };

  using TokenEntityList = std::vector<TokenEntity>;
  using TokenEntityRowList = std::vector<TokenEntityList>;

  struct SceneRow final {
    QRectF bounding_box;
    TokenEntityList entity_list;
  };

  using SceneRowList = std::vector<SceneRow>;

  struct Cursor final {
    TokenID token_id;
    std::size_t offset{};
  };

  struct Selection final {
    bool tracking{false};
    Cursor first_cursor;
    Cursor last_cursor;
  };

  using OptionalSelection = std::optional<Selection>;

  struct Scene final {
    SceneRowList row_list;
  };

  using OptionalScene = std::optional<Scene>;

  struct Context final {
    QRectF viewport;
    QPixmap viewport_surface;
    GlyphCache::Ptr glyph_cache;
    TextViewTheme theme;

    std::unique_ptr<QFontMetricsF> font_metrics;
    TokenEntityRowList token_index;

    OptionalScene opt_scene;
    OptionalSelection opt_selection;
    bool word_wrap{true};
  };

  static void resizeViewport(Context &context, qreal pixel_ratio, const QSizeF &size);
  static void moveViewport(Context &context, const QPointF &point);
  static void drawViewport(Context &context, const TextModel &model);

  static void createTokenIndex(Context &context, TextModel &model);
  static void resetScene(Context &context);
  static void generateScene(Context &context);
  static std::optional<Cursor> createCursor(Context &context, const QPointF &pos);
  static void sanitizeSelection(Selection &selection);

signals:
  void tokenClicked(const QPoint &mouse_position, const Qt::MouseButton &button, TokenID token_id);
};

} // namespace drgui
