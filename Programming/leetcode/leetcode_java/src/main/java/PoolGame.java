import javax.swing.*;
import java.awt.*;
import java.awt.event.MouseAdapter;
import java.awt.event.MouseEvent;

public class PoolGame extends JFrame {

    private int ballX = 50;
    private int ballY = 50;
    private int ballSize = 20;

    public PoolGame() {
        setTitle("Pool Game");
        setSize(400, 400);
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        setResizable(false);

        PoolPanel poolPanel = new PoolPanel();
        add(poolPanel);

        addMouseListener(new MouseAdapter() {
            @Override
            public void mouseClicked(MouseEvent e) {
                poolPanel.hitBall(e.getX(), e.getY());
            }
        });
    }

    private class PoolPanel extends JPanel {

        public void hitBall(int mouseX, int mouseY) {
            // 计算击球的方向和力度，并更新小球的位置
            double angle = Math.atan2(mouseY - ballY, mouseX - ballX);
            int speed = 5;
            ballX += (int) (speed * Math.cos(angle));
            ballY += (int) (speed * Math.sin(angle));
            repaint();
        }

        @Override
        protected void paintComponent(Graphics g) {
            super.paintComponent(g);
            g.setColor(Color.GREEN);
            g.fillRect(0, 0, getWidth(), getHeight()); // 绘制台球桌

            g.setColor(Color.WHITE);
            g.fillOval(ballX - ballSize / 2, ballY - ballSize / 2, ballSize, ballSize); // 绘制白球
        }
    }

    public static void main(String[] args) {
        SwingUtilities.invokeLater(() -> {
            PoolGame poolGame = new PoolGame();
            poolGame.setVisible(true);
        });
    }
}
